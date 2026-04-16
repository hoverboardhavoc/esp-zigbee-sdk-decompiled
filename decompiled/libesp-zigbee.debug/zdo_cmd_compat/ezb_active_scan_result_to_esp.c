/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> ezb_active_scan_result_to_esp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_active_scan_result_to_esp
               (ezb_nwk_active_scan_result_t *ezb,esp_zb_network_descriptor_t *esp)

{
  uint8_t uVar1;
  uint8_t uVar2;
  uint8_t uVar3;
  uint8_t uVar4;
  uint8_t uVar5;
  uint8_t uVar6;
  uint8_t uVar7;
  
  esp->short_pan_id = ezb->panid;
  esp->permit_joining = (_Bool)((byte)*(undefined2 *)&ezb->field_0x10 & 1);
  uVar1 = (ezb->extpanid).field_0.u8[1];
  uVar2 = (ezb->extpanid).field_0.u8[2];
  uVar3 = (ezb->extpanid).field_0.u8[3];
  uVar4 = (ezb->extpanid).field_0.u8[4];
  uVar5 = (ezb->extpanid).field_0.u8[5];
  uVar6 = (ezb->extpanid).field_0.u8[6];
  uVar7 = (ezb->extpanid).field_0.u8[7];
  esp->extended_pan_id[0] = (ezb->extpanid).field_0.u8[0];
  esp->extended_pan_id[1] = uVar1;
  esp->extended_pan_id[2] = uVar2;
  esp->extended_pan_id[3] = uVar3;
  esp->extended_pan_id[4] = uVar4;
  esp->extended_pan_id[5] = uVar5;
  esp->extended_pan_id[6] = uVar6;
  esp->extended_pan_id[7] = uVar7;
  esp->logic_channel = ezb->channel_number;
  esp->router_capacity = (_Bool)((byte)(*(ushort *)&ezb->field_0x10 >> 1) & 1);
  esp->end_device_capacity = (_Bool)((byte)(*(ushort *)&ezb->field_0x10 >> 2) & 1);
  return;
}

