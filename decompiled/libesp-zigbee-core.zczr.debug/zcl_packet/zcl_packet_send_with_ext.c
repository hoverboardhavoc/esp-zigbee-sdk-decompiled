/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_send_with_ext
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_packet_send_with_ext(int param_1,undefined4 *param_2,byte *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  byte bVar4;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  if (param_1 == 0) {
    uVar3 = 1;
  }
  else {
    zcl_frame_fill_header();
    uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (param_3 == (byte *)0x0) {
      bVar4 = 0;
    }
    else {
      bVar4 = *param_3 & 1;
    }
    uVar2 = zcl_packet_max_available_space
                      (*(undefined2 *)(param_1 + 0x16),bVar4,*(byte *)(param_1 + 0x1a) >> 2 & 1);
    if (uVar2 < uVar1) {
      uVar3 = 0x89;
    }
    else {
      uStack_44 = 0;
      uStack_40 = 0;
      uStack_3c = 0;
      uStack_38 = 0;
      uStack_34 = 0;
      uStack_30 = 0;
      uStack_2c = 0;
      uStack_28 = 0;
      uStack_24 = 0;
      uStack_44 = zcl_packet_transfer_ownership(param_1);
      uStack_40 = *(undefined4 *)(param_1 + 10);
      uStack_3c = *(undefined4 *)(param_1 + 0xe);
      uStack_38 = *(undefined4 *)(param_1 + 0x12);
      uStack_34 = *(undefined4 *)(param_1 + 0x16);
      if (param_3 == (byte *)0x0) {
        uStack_2c._0_1_ = (byte)uStack_2c & 0xfe | 2;
        uVar1 = zcl_packet_fragment_is_supported(param_1);
        uStack_2c._0_1_ = (byte)uStack_2c & 0xf3 | (byte)((uVar1 & 1) << 2);
        uVar1 = 0;
      }
      else {
        bVar4 = *param_3;
        uStack_2c._0_1_ =
             (byte)uStack_2c & 0xf0 | bVar4 & 1 | (byte)((bVar4 >> 1 & 1) << 1) |
             (byte)((bVar4 >> 2 & 1) << 2) | (byte)((bVar4 >> 3 & 1) << 3);
        uVar1 = bVar4 >> 4 & 1;
      }
      uStack_2c = CONCAT31(uStack_2c._1_3_,(byte)(uVar1 << 4) | (byte)uStack_2c & 0xef);
      if (param_2 == (undefined4 *)0x0) {
        uStack_28 = 0;
        uStack_24 = 0;
      }
      else {
        uStack_28 = *param_2;
        uStack_24 = param_2[1];
      }
      af_data_request(&uStack_44);
      uVar3 = err_to_zcl_status();
    }
  }
  return uVar3;
}

