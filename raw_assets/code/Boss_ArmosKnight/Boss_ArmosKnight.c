#include <z64hdr/oot_mq_debug/z64hdr.h>
#define OBJ_ID 0x4 // OBJECT ID
#define ACT_ID 0x1 // ACTOR ID
#define PAD 0x0

#define MODEL_BODY 0x060031A0 // Main body mesh
#define MODEL_EYE 0x06003968  // Eye mesh
#define COLLISION 0x060018A0  // Collision mesh

typedef struct
{
    DynaPolyActor dyna;
    GfxPrint printer;

    s16 hopTimer; // Determines the time between the Armos becoming grounded and its next hop

    /* I have no clue what I'm doing so these are just variables that I may or may not use
    s16 mouthOpenTimer;
    s16 laserChargeTimer;
    s16 laserUsageTimer;
    */

    bool beginLanding;

    /*
    bool mouthOpen;
    bool chargingLaser;
    bool usingLaser;
    */
} entity_t;

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(targetArrowOffset, 2000, ICHAIN_CONTINUE),
};

void Armos_Move(entity_t *en, GlobalContext *global)
{
    en->hopTimer--;

    // Begin hop movement
    if (en->hopTimer <= 0 && en->dyna.actor.world.pos.y <= en->dyna.actor.floorHeight)
    {
        en->dyna.actor.world.pos.y = en->dyna.actor.world.pos.y + 10.0f;
        en->dyna.actor.speedXZ = 10.0f;
        en->dyna.actor.velocity.y = 6.0f;
        en->dyna.actor.gravity = -1.0f;
        Audio_PlayActorSound2(&en->dyna.actor, NA_SE_EN_STAL_JUMP);
        en->hopTimer = 30;
        en->beginLanding = true;
    }

    // Checks for ground
    if (en->beginLanding)
    {
        if (en->dyna.actor.world.pos.y <= en->dyna.actor.floorHeight)
        {
            en->dyna.actor.speedXZ = 0.0f;
            en->dyna.actor.velocity.y = 0.0f;
            en->dyna.actor.gravity = 0.0f;
            en->beginLanding = false;
            Audio_PlayActorSound2(&en->dyna.actor, NA_SE_EN_DODO_K_WALK);
        }
    }

    Actor_MoveForward(&en->dyna.actor);
}

void Armos_FaceLink(entity_t *en, GlobalContext *global)
{
    // Copied from the dog actor
    if (en->dyna.actor.world.pos.y > en->dyna.actor.floorHeight) // Only rotate when hopping
    {
        s16 rotTowardLink;
        s16 prevRotY;
        f32 absAngleDiff;

        rotTowardLink = en->dyna.actor.yawTowardsPlayer;
        prevRotY = en->dyna.actor.world.rot.y;

        // This line adjusts rotation speed
        Math_ApproachS(&en->dyna.actor.world.rot.y, rotTowardLink, 10, 3500);

        absAngleDiff = en->dyna.actor.world.rot.y;
        absAngleDiff -= prevRotY;
        absAngleDiff = fabsf(absAngleDiff);

        en->dyna.actor.shape.rot = en->dyna.actor.world.rot;
    }
}

static void init(entity_t *en, GlobalContext *global)
{
    Actor_ProcessInitChain(en, sInitChain);
    en->dyna.actor.targetMode = 4;

    en->hopTimer = 30;

    Actor_SetScale(&en->dyna.actor, 1.0f);

    // Collision
    CollisionHeader *colHeader = NULL;
    DynaPolyActor_Init(&en->dyna, 0);
    CollisionHeader_GetVirtual(COLLISION, &colHeader);
    en->dyna.bgId = DynaPoly_SetBgActor(global, &global->colCtx.dyna, &en->dyna.actor, colHeader);
}

static void update(entity_t *en, GlobalContext *global)
{
    Armos_Move(en, global);
    Armos_FaceLink(en, global);
}

static void dest(entity_t *en, GlobalContext *global)
{
    DynaPoly_DeleteBgActor(global, &global->colCtx.dyna, en->dyna.bgId);
}

static void draw(entity_t *en, GlobalContext *global)
{
    // Model
    Gfx_DrawDListOpa(global, MODEL_BODY);
    Gfx_DrawDListOpa(global, MODEL_EYE);

    // Printer, thanks Dragorn
    Gfx *gfx = global->state.gfxCtx->polyOpa.p + 1;
    gSPDisplayList(global->state.gfxCtx->overlay.p++, gfx);

    GfxPrint_Init(&en->printer);
    GfxPrint_Open(&en->printer, gfx);
    GfxPrint_SetColor(&en->printer, 255, 0, 0, 255);
    GfxPrint_SetPos(&en->printer, 1, 1);

    if (en->beginLanding)
    {
        GfxPrint_Printf(&en->printer, "true", en);
    }
    else
    {
        GfxPrint_Printf(&en->printer, "false", en);
    }

    gfx = GfxPrint_Close(&en->printer);
    GfxPrint_Destroy(&en->printer);
    gSPEndDisplayList(gfx++);
    gSPBranchList(global->state.gfxCtx->polyOpa.p, gfx);
    global->state.gfxCtx->polyOpa.p = gfx;
}

const ActorInit init_vars = {
    ACT_ID,
    0x06,
    0x00000030,
    OBJ_ID,
    sizeof(entity_t),
    (ActorFunc)init,
    (ActorFunc)dest,
    (ActorFunc)update,
    (ActorFunc)draw};