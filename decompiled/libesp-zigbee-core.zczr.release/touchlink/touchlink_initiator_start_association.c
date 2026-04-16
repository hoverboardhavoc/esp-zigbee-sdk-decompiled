/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink.o -> touchlink_initiator_start_association
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_initiator_start_association(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  ezb_err_t eVar3;
  _Bool _Var4;
  uint8_t logic_channel;
  int iVar5;
  int iVar6;
  undefined3 extraout_var;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  byte bVar10;
  int iVar11;
  byte bVar12;
  int iVar13;
  
  iVar5 = core_globals_get();
  if (*(int *)(iVar5 + 0x1414) == 0) {
    bVar12 = 0;
    iVar5 = -0x80;
    puVar2 = (undefined4 *)0x0;
    for (uVar8 = 0; iVar6 = core_globals_get(), uVar8 < *(byte *)(iVar6 + 0xdd4);
        uVar8 = uVar8 + 1 & 0xff) {
      iVar6 = core_globals_get();
      iVar13 = iVar6 + uVar8 * 0xc0;
      if (((((*(ushort *)(iVar13 + 0xde0) & 3) == 1) ||
           (iVar11 = touchlink_is_factory_new(), iVar11 == 0)) ||
          (((*(ushort *)(iVar13 + 0xde0) & 3) == 2 &&
           (uVar9 = touchlink_zigbee_info(), (uVar9 & 3) == 1)))) &&
         (iVar11 = (int)(((uint)*(byte *)(iVar6 + uVar8 * 0xc0 + 0xe94) +
                         (uint)*(byte *)(iVar13 + 0xde6)) * 0x1000000) >> 0x18, iVar5 < iVar11)) {
        bVar10 = *(byte *)(iVar13 + 0xde2) & 1;
        if (bVar10 < bVar12) {
          bVar12 = 1;
        }
        else {
          puVar2 = (undefined4 *)(iVar6 + uVar8 * 0xc0 + 0xdd8);
          iVar5 = iVar11;
          bVar12 = bVar10;
        }
      }
    }
    if (puVar2 == (undefined4 *)0x0) {
      return 5;
    }
    _Var4 = touchlink_commissioning_action_permission
                      (TOUCHLINK_ACTION_SELECTED_TARGET,(ezb_extaddr_t *)((int)puVar2 + 0xf));
    puVar1 = (undefined4 *)CONCAT31(extraout_var,_Var4);
  }
  else {
    iVar5 = core_globals_get();
    puVar2 = *(undefined4 **)(iVar5 + 0x1414);
    puVar1 = puVar2;
  }
  if (puVar1 == (undefined4 *)0x0) {
    return 5;
  }
  iVar5 = core_globals_get();
  *(undefined4 **)(iVar5 + 0x1414) = puVar2;
  touchlink_set_transaction_id(*puVar2);
  touchlink_set_intrp_channel(*(undefined1 *)((int)puVar2 + 0x21));
  piVar7 = (int *)touchlink_extended_address();
  if ((*(int *)((int)puVar2 + 0xf) == *piVar7) && (*(int *)((int)puVar2 + 0x13) == piVar7[1])) {
    touchlink_send_network_update_req(puVar2,0);
    uVar8 = touchlink_touchlink_info();
    if ((uVar8 & 2) != 0) {
      return 0;
    }
    touchlink_zdo_rejoin_network(0);
    return 0;
  }
  iVar5 = touchlink_is_factory_new();
  if (iVar5 != 0) {
    _Var4 = touchlink_commissioning_task_is_idle();
    eVar3 = 2;
    if (CONCAT31(extraout_var_00,_Var4) == 0) goto _L0;
    _Var4 = touchlink_commissioning_action_permission
                      (TOUCHLINK_ACTION_START_NEW_NETWORK,(ezb_extaddr_t *)((int)puVar2 + 0xf));
    eVar3 = -1;
    if (CONCAT31(extraout_var_01,_Var4) == 0) goto _L0;
    uVar8 = touchlink_touchlink_info();
    if ((uVar8 & 2) != 0) {
      touchlink_commissioning_set_task('\x03');
      logic_channel = touchlink_get_logical_channel();
      touchlink_commissioning_set_logic_channel(logic_channel);
      touchlink_zdo_network_discovery();
      return 0;
    }
    touchlink_commissioning_set_task('\x04');
    eVar3 = touchlink_send_network_start_req(puVar2);
    goto _L0;
  }
  _Var4 = touchlink_commissioning_task_is_idle();
  if (CONCAT31(extraout_var_02,_Var4) != 0) {
    if ((*(ushort *)(puVar2 + 2) & 3) == 1) {
      _Var4 = touchlink_commissioning_task_is_idle();
      if (CONCAT31(extraout_var_03,_Var4) != 0) {
        _Var4 = touchlink_commissioning_action_permission
                          (TOUCHLINK_ACTION_JOIN_ROUTER,(ezb_extaddr_t *)((int)puVar2 + 0xf));
        if (CONCAT31(extraout_var_04,_Var4) == 0) {
_L172:
          eVar3 = -1;
          goto _L0;
        }
        touchlink_commissioning_set_task('\x05');
        eVar3 = touchlink_send_join_router_req(puVar2);
_L0:
        if (eVar3 == 0) {
          return 0;
        }
        goto _L0;
      }
    }
    else {
      _Var4 = touchlink_commissioning_task_is_idle();
      if (CONCAT31(extraout_var_05,_Var4) != 0) {
        _Var4 = touchlink_commissioning_action_permission
                          (TOUCHLINK_ACTION_JOIN_ED,(ezb_extaddr_t *)((int)puVar2 + 0xf));
        if (CONCAT31(extraout_var_06,_Var4) == 0) goto _L172;
        touchlink_commissioning_set_task('\x06');
        eVar3 = touchlink_send_join_ed_req(puVar2);
        goto _L0;
      }
    }
  }
  eVar3 = 2;
_L0:
  touchlink_commissioning_set_task('\0');
  return eVar3;
}

