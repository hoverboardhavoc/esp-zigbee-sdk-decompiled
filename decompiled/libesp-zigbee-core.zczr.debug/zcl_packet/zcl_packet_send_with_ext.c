/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_send_with_ext
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_packet_send_with_ext(int param_1,undefined4 *param_2,byte *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
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
    uVar2 = 1;
  }
  else {
    iVar1 = zcl_packet_is_device_allowed(0);
    if (iVar1 == 0) {
      uVar2 = 1;
    }
    else {
      zcl_frame_fill_header(param_1);
      uVar3 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
      if (param_3 == (byte *)0x0) {
        bVar5 = 0;
      }
      else {
        bVar5 = *param_3 & 1;
      }
      uVar4 = zcl_packet_max_available_space
                        (*(undefined2 *)(param_1 + 0x16),bVar5,*(byte *)(param_1 + 0x1a) >> 2 & 1);
      if (uVar4 < uVar3) {
        uVar2 = 0x89;
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
          uVar3 = zcl_packet_fragment_is_supported(param_1);
          uStack_2c._0_1_ = (byte)uStack_2c & 0xf3 | (byte)((uVar3 & 1) << 2);
          uVar3 = 0;
        }
        else {
          bVar5 = *param_3;
          uStack_2c._0_1_ =
               (byte)uStack_2c & 0xf0 | bVar5 & 1 | (byte)((bVar5 >> 1 & 1) << 1) |
               (byte)((bVar5 >> 2 & 1) << 2) | (byte)((bVar5 >> 3 & 1) << 3);
          uVar3 = bVar5 >> 4 & 1;
        }
        uStack_2c = CONCAT31(uStack_2c._1_3_,(byte)(uVar3 << 4) | (byte)uStack_2c & 0xef);
        if (param_2 == (undefined4 *)0x0) {
          uStack_28 = 0;
          uStack_24 = 0;
        }
        else {
          uStack_28 = *param_2;
          uStack_24 = param_2[1];
        }
        af_data_request(&uStack_44);
        uVar2 = err_to_zcl_status();
      }
    }
  }
  return uVar2;
}

