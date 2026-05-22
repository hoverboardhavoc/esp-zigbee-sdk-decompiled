/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> af_core.o -> af_data_schedule_cnf_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_data_schedule_cnf_cb(aps_apsde_data_cnf_t *cnf)

{
  uint16_t uVar1;
  undefined4 *unaff_s0;
  ezb_err_t eVar2;
  int iVar3;
  int iVar4;
  
  if (cnf == (aps_apsde_data_cnf_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/af/af_core.c",0x57,
                  "af_data_schedule_cnf_cb",0x10000);
    goto _L0;
  }
  iVar3 = core_globals_get();
  iVar3 = *(int *)(iVar3 + 0xca4);
  if (iVar3 == 0) {
    eVar2 = 5;
  }
  else {
    while (unaff_s0 = (undefined4 *)(iVar3 + -0xc), unaff_s0 != (undefined4 *)0xfffffff4) {
      if ((unaff_s0 != (undefined4 *)0x0) && ((zmsg_t *)*unaff_s0 == cnf->asdu)) {
        iVar4 = core_globals_get();
        list_remove_node(iVar4 + 0xca4,iVar3);
        break;
      }
_L0:
      iVar3 = unaff_s0[3];
    }
    if (unaff_s0 == (undefined4 *)0xfffffff4) {
      eVar2 = 5;
    }
    else if (unaff_s0 == (undefined4 *)0x0) {
      eVar2 = 5;
    }
    else {
      uVar1 = cnf->profile_id;
      if ((uVar1 == 0x104) || (uVar1 == 0xc05e)) {
        zcl_confirm_handler(cnf,iVar3 + -8);
        eVar2 = 0;
      }
      else if (uVar1 == 0) {
        zdo_confirm_handler(cnf,iVar3 + -8);
        eVar2 = 0;
      }
      else {
        eVar2 = 6;
      }
      mm_free(unaff_s0);
    }
  }
  return eVar2;
}

