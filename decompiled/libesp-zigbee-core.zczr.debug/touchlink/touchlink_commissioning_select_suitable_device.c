/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_commissioning_select_suitable_device
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

touchlink_disc_dev_info_t * touchlink_commissioning_select_suitable_device(void)

{
  uint uVar1;
  _Bool _Var2;
  touchlink_transaction_t *ptVar3;
  uint uVar4;
  undefined3 extraout_var;
  int iVar5;
  byte bVar6;
  int iVar7;
  touchlink_disc_dev_info_t *ptVar8;
  byte bVar9;
  
  bVar9 = 0;
  iVar7 = -0x80;
  ptVar8 = (touchlink_disc_dev_info_t *)0x0;
  for (uVar1 = 0; ptVar3 = touchlink_transaction_get(),
      uVar1 < (ptVar3->field_2).cli.disc_table_count; uVar1 = uVar1 + 1 & 0xff) {
    ptVar3 = touchlink_transaction_get();
    if ((((*(ushort *)((int)&ptVar3->field_2 + uVar1 * 0xc0 + 0xc) & 3) == 1) ||
        (iVar5 = touchlink_is_factory_new(), iVar5 == 0)) ||
       (((*(ushort *)((int)&ptVar3->field_2 + uVar1 * 0xc0 + 0xc) & 3) == 2 &&
        (uVar4 = touchlink_zigbee_info(), (uVar4 & 3) == 1)))) {
      iVar5 = (int)(((uint)*(byte *)((int)&ptVar3->field_2 + uVar1 * 0xc0 + 0x12) +
                    (uint)*(byte *)((int)&ptVar3->field_2 + uVar1 * 0xc0 + 0xc0)) * 0x1000000) >>
              0x18;
      bVar6 = *(byte *)((int)&ptVar3->field_2 + uVar1 * 0xc0 + 0xe) & 1;
      if ((iVar7 < iVar5) && (bVar9 <= bVar6)) {
        iVar7 = iVar5;
        ptVar8 = (touchlink_disc_dev_info_t *)((int)&ptVar3->field_2 + uVar1 * 0xc0 + 4);
        bVar9 = bVar6;
      }
    }
  }
  if ((ptVar8 == (touchlink_disc_dev_info_t *)0x0) ||
     (_Var2 = touchlink_commissioning_action_permission
                        (TOUCHLINK_ACTION_SELECTED_TARGET,&(ptVar8->basic).ieee_addr),
     CONCAT31(extraout_var,_Var2) == 0)) {
    ptVar8 = (touchlink_disc_dev_info_t *)0x0;
  }
  return ptVar8;
}

