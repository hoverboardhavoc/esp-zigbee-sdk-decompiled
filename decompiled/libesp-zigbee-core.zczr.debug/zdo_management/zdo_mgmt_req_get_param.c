/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_management.o -> zdo_mgmt_req_get_param
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdo_mgmt_req_param_t * zdo_mgmt_req_get_param(zdo_mgmt_req_handle_t handle)

{
  void *arg;
  int iVar1;
  zdo_mgmt_req_param_t *pzVar2;
  int extraout_a1;
  int *piVar3;
  
  if (handle != (zdo_mgmt_req_handle_t)0x0) {
    return (zdo_mgmt_req_param_t *)((int)handle + 8);
  }
  arg = (void *)__assert_func("//build/esp-zigbee/src/core/zdo/zdo_management.c",0x66,
                              "zdo_mgmt_req_get_param","handle != ((void *)0)");
  if (arg == (void *)0x0) {
    pzVar2 = (zdo_mgmt_req_param_t *)0x2;
  }
  else {
    iVar1 = core_globals_get();
    piVar3 = (int *)(iVar1 + 0xd44);
    iVar1 = *piVar3;
    while (iVar1 != 0) {
      piVar3 = (int *)*piVar3;
      iVar1 = *piVar3;
    }
    *(undefined4 *)((int)arg + 4) = 0;
    *piVar3 = (int)arg + 4;
    if (extraout_a1 == 0) {
      iVar1 = core_globals_get();
      tasklet_post(iVar1 + 0xd48);
      pzVar2 = (zdo_mgmt_req_param_t *)0x0;
    }
    else {
      zdo_mgmt_task(arg);
      pzVar2 = (zdo_mgmt_req_param_t *)0x0;
    }
  }
  return pzVar2;
}

