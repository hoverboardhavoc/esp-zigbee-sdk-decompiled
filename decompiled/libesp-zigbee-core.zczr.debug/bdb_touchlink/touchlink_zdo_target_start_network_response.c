/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> touchlink_zdo_target_start_network_response
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void touchlink_zdo_target_start_network_response(touchlink_event_start_network_t *start_network)

{
  undefined4 uVar1;
  undefined3 uVar2;
  undefined4 uVar3;
  uint8_t uVar4;
  ezb_panid_t eVar5;
  int iVar6;
  undefined4 *puVar7;
  
  iVar6 = core_globals_get();
  if (*(int *)(iVar6 + 0xc) == 0 && *(int *)(iVar6 + 0x10) == 0) {
    puVar7 = (undefined4 *)nwk_get_extended_address();
    uVar1 = *puVar7;
    uVar2 = *(undefined3 *)(puVar7 + 1);
    uVar3 = puVar7[1];
    (start_network->ext_panid).field_0.u8[0] = (uint8_t)*(undefined3 *)puVar7;
    (start_network->ext_panid).field_0.u8[1] = (uint8_t)((uint)uVar1 >> 8);
    (start_network->ext_panid).field_0.u8[2] = (uint8_t)((uint)uVar1 >> 0x10);
    (start_network->ext_panid).field_0.u8[3] = (uint8_t)((uint)uVar1 >> 0x18);
    (start_network->ext_panid).field_0.u8[4] = (uint8_t)uVar2;
    (start_network->ext_panid).field_0.u8[5] = (uint8_t)((uint)uVar3 >> 8);
    (start_network->ext_panid).field_0.u8[6] = (uint8_t)((uint)uVar3 >> 0x10);
    (start_network->ext_panid).field_0.u8[7] = (uint8_t)((uint)uVar3 >> 0x18);
  }
  else {
    iVar6 = core_globals_get();
    uVar1 = *(undefined4 *)(iVar6 + 0xc);
    uVar2 = *(undefined3 *)(iVar6 + 0x10);
    uVar3 = *(undefined4 *)(iVar6 + 0x10);
    (start_network->ext_panid).field_0.u8[0] = (uint8_t)*(undefined3 *)(iVar6 + 0xc);
    (start_network->ext_panid).field_0.u8[1] = (uint8_t)((uint)uVar1 >> 8);
    (start_network->ext_panid).field_0.u8[2] = (uint8_t)((uint)uVar1 >> 0x10);
    (start_network->ext_panid).field_0.u8[3] = (uint8_t)((uint)uVar1 >> 0x18);
    (start_network->ext_panid).field_0.u8[4] = (uint8_t)uVar2;
    (start_network->ext_panid).field_0.u8[5] = (uint8_t)((uint)uVar3 >> 8);
    (start_network->ext_panid).field_0.u8[6] = (uint8_t)((uint)uVar3 >> 0x10);
    (start_network->ext_panid).field_0.u8[7] = (uint8_t)((uint)uVar3 >> 0x18);
  }
  if (start_network->channel == '\0') {
    uVar4 = touchlink_assign_random_channel();
    start_network->channel = uVar4;
  }
  eVar5 = touchlink_validate_pan_id(start_network->pan_id);
  start_network->pan_id = eVar5;
  touchlink_send_network_start_rsp(start_network);
  return;
}

