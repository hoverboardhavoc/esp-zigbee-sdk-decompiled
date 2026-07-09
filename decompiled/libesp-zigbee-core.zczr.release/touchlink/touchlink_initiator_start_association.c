/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink.o -> touchlink_initiator_start_association
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int touchlink_initiator_start_association(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  byte bVar8;
  int iVar9;
  byte bVar10;
  int iVar11;
  
  iVar2 = core_globals_get();
  if (*(int *)(iVar2 + 0x13c0) == 0) {
    bVar10 = 0;
    iVar2 = -0x80;
    puVar1 = (undefined4 *)0x0;
    for (uVar5 = 0; iVar7 = core_globals_get(), uVar5 < *(byte *)(iVar7 + 0xd80);
        uVar5 = uVar5 + 1 & 0xff) {
      iVar7 = core_globals_get();
      iVar11 = iVar7 + uVar5 * 0xc0;
      if (((((*(ushort *)(iVar11 + 0xd8c) & 3) == 1) ||
           (iVar9 = touchlink_is_factory_new(), iVar9 == 0)) ||
          (((*(ushort *)(iVar11 + 0xd8c) & 3) == 2 &&
           (uVar6 = touchlink_zigbee_info(), (uVar6 & 3) == 1)))) &&
         (iVar9 = (int)(((uint)*(byte *)(iVar7 + uVar5 * 0xc0 + 0xe40) +
                        (uint)*(byte *)(iVar11 + 0xd92)) * 0x1000000) >> 0x18, iVar2 < iVar9)) {
        bVar8 = *(byte *)(iVar11 + 0xd8e) & 1;
        if (bVar8 < bVar10) {
          bVar10 = 1;
        }
        else {
          puVar1 = (undefined4 *)(iVar7 + uVar5 * 0xc0 + 0xd84);
          iVar2 = iVar9;
          bVar10 = bVar8;
        }
      }
    }
    if (puVar1 == (undefined4 *)0x0) {
      return 5;
    }
    puVar3 = (undefined4 *)touchlink_commissioning_action_permission(0,(int)puVar1 + 0xf);
  }
  else {
    iVar2 = core_globals_get();
    puVar1 = *(undefined4 **)(iVar2 + 0x13c0);
    puVar3 = puVar1;
  }
  if (puVar3 == (undefined4 *)0x0) {
    return 5;
  }
  iVar2 = core_globals_get();
  *(undefined4 **)(iVar2 + 0x13c0) = puVar1;
  touchlink_set_transaction_id(*puVar1);
  touchlink_set_intrp_channel(*(undefined1 *)((int)puVar1 + 0x21));
  piVar4 = (int *)touchlink_extended_address();
  if ((*(int *)((int)puVar1 + 0xf) == *piVar4) && (*(int *)((int)puVar1 + 0x13) == piVar4[1])) {
    touchlink_send_network_update_req(puVar1,0);
    uVar5 = touchlink_touchlink_info();
    if ((uVar5 & 2) != 0) {
      return 0;
    }
    touchlink_zdo_rejoin_network(0);
    return 0;
  }
  iVar2 = touchlink_is_factory_new();
  if (iVar2 != 0) {
    iVar7 = touchlink_commissioning_task_is_idle();
    iVar2 = 2;
    if (iVar7 == 0) goto _L0;
    iVar7 = touchlink_commissioning_action_permission(1,(int)puVar1 + 0xf);
    iVar2 = -1;
    if (iVar7 == 0) goto _L0;
    uVar5 = touchlink_touchlink_info();
    if ((uVar5 & 2) != 0) {
      touchlink_commissioning_set_task(3);
      touchlink_get_logical_channel();
      touchlink_commissioning_set_logic_channel();
      touchlink_zdo_network_discovery();
      return 0;
    }
    touchlink_commissioning_set_task(4);
    iVar2 = touchlink_send_network_start_req(puVar1);
    goto _L0;
  }
  iVar2 = touchlink_commissioning_task_is_idle();
  if (iVar2 != 0) {
    if ((*(ushort *)(puVar1 + 2) & 3) == 1) {
      iVar2 = touchlink_commissioning_task_is_idle();
      if (iVar2 != 0) {
        iVar2 = touchlink_commissioning_action_permission(2,(int)puVar1 + 0xf);
        if (iVar2 == 0) {
_L172:
          iVar2 = -1;
          goto _L0;
        }
        touchlink_commissioning_set_task(5);
        iVar2 = touchlink_send_join_router_req(puVar1);
_L0:
        if (iVar2 == 0) {
          return 0;
        }
        goto _L0;
      }
    }
    else {
      iVar2 = touchlink_commissioning_task_is_idle();
      if (iVar2 != 0) {
        iVar2 = touchlink_commissioning_action_permission(3,(int)puVar1 + 0xf);
        if (iVar2 == 0) goto _L172;
        touchlink_commissioning_set_task(6);
        iVar2 = touchlink_send_join_ed_req(puVar1);
        goto _L0;
      }
    }
  }
  iVar2 = 2;
_L0:
  touchlink_commissioning_set_task(0);
  return iVar2;
}

