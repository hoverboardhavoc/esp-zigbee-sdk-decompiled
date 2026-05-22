/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  arg = (void *)__assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_management.c",0x66
                              ,"zdo_mgmt_req_get_param","handle != ((void *)0)");
  if (arg == (void *)0x0) {
    pzVar2 = (zdo_mgmt_req_param_t *)0x2;
  }
  else {
    iVar1 = core_globals_get();
    piVar3 = (int *)(iVar1 + 0xce0);
    iVar1 = *piVar3;
    while (iVar1 != 0) {
      piVar3 = (int *)*piVar3;
      iVar1 = *piVar3;
    }
    *(undefined4 *)((int)arg + 4) = 0;
    *piVar3 = (int)arg + 4;
    if (extraout_a1 == 0) {
      iVar1 = core_globals_get();
      tasklet_post(iVar1 + 0xce4);
      pzVar2 = (zdo_mgmt_req_param_t *)0x0;
    }
    else {
      zdo_mgmt_task(arg);
      pzVar2 = (zdo_mgmt_req_param_t *)0x0;
    }
  }
  return pzVar2;
}

