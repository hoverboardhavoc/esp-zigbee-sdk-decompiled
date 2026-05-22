/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_management.o -> zdo_mgmt_req_set_user_ctx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_mgmt_req_set_user_ctx(zdo_mgmt_req_handle_t handle,zdo_mgmt_req_user_ctx_t *ctx)

{
  int iVar1;
  void *arg;
  int extraout_a1;
  int *piVar2;
  
  if (handle != (zdo_mgmt_req_handle_t)0x0) {
    *(zdo_mgmt_user_callback_t *)((int)handle + 0x18) = ctx->cb;
    *(void **)((int)handle + 0x1c) = ctx->arg;
    return;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_management.c",0x5f,
                        "zdo_mgmt_req_set_user_ctx","handle != ((void *)0)");
  if (iVar1 == 0) {
    arg = (void *)__assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_management.c",
                                0x66,"zdo_mgmt_req_get_param","handle != ((void *)0)");
    if (arg != (void *)0x0) {
      iVar1 = core_globals_get();
      piVar2 = (int *)(iVar1 + 0xce0);
      iVar1 = *piVar2;
      while (iVar1 != 0) {
        piVar2 = (int *)*piVar2;
        iVar1 = *piVar2;
      }
      *(undefined4 *)((int)arg + 4) = 0;
      *piVar2 = (int)arg + 4;
      if (extraout_a1 == 0) {
        iVar1 = core_globals_get();
        tasklet_post(iVar1 + 0xce4);
      }
      else {
        zdo_mgmt_task(arg);
      }
    }
    return;
  }
  return;
}

