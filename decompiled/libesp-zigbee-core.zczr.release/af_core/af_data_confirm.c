/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> af_core.o -> af_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void af_data_confirm(aps_apsde_data_cnf_t *cnf)

{
  uint16_t uVar1;
  int *piVar2;
  undefined4 *puVar3;
  aps_apsde_data_cnf_t *extraout_a0;
  int iVar4;
  
  if (cnf == (aps_apsde_data_cnf_t *)0x0) {
    af_data_indication_deliver_ep_handler((void *)0x0);
    cnf = extraout_a0;
  }
  iVar4 = core_globals_get();
  piVar2 = *(int **)(iVar4 + 0xd08);
  if (piVar2 != (int *)0x0) {
    for (; puVar3 = piVar2 + -3, puVar3 != (undefined4 *)0xfffffff4; piVar2 = (int *)*piVar2) {
      if ((zmsg_t *)*puVar3 == cnf->asdu) {
        iVar4 = core_globals_get();
        list_remove_node(iVar4 + 0xd08,piVar2);
        uVar1 = cnf->profile_id;
        if ((uVar1 == 0x104) || (uVar1 == 0xc05e)) {
          zcl_confirm_handler(cnf,piVar2 + -2);
        }
        else if (uVar1 == 0) {
          zdo_confirm_handler(cnf,piVar2 + -2);
        }
        mm_free(puVar3);
        break;
      }
    }
  }
  zmsg_free(cnf->asdu);
  return;
}

