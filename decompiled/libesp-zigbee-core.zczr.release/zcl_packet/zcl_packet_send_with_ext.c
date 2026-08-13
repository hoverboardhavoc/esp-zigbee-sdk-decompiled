/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_send_with_ext
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_packet_send_with_ext(int param_1,undefined4 *param_2,byte *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  byte bVar5;
  undefined4 uStack_44;
  undefined1 auStack_40 [10];
  undefined2 uStack_36;
  undefined2 uStack_34;
  undefined2 uStack_32;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  if (param_1 == 0) {
    return 1;
  }
  iVar1 = zcl_basic_device_is_enabled(*(undefined1 *)(param_1 + 0x14));
  if ((iVar1 == 0) && (iVar1 = zcl_packet_is_device_allowed_part_0(param_1), iVar1 == 0)) {
    uVar4 = 1;
  }
  else {
    zcl_frame_fill_header_isra_0(param_1);
    uVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    bVar5 = 0;
    if (param_3 != (byte *)0x0) {
      bVar5 = *param_3 & 1;
    }
    uVar3 = zcl_packet_max_available_space
                      (*(undefined2 *)(param_1 + 0x16),bVar5,*(ushort *)(param_1 + 0x1a) >> 2 & 1);
    uVar4 = 0x89;
    if (uVar2 <= uVar3) {
      uStack_44 = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(param_1 + 0x24) = 0;
      uStack_30 = 0;
      uStack_2c = 0;
      uStack_28 = 0;
      uStack_24 = 0;
      memcpy(auStack_40,(void *)(param_1 + 10),10);
      uStack_34 = *(undefined2 *)(param_1 + 0x16);
      uStack_32 = *(undefined2 *)(param_1 + 0x18);
      uStack_36 = *(undefined2 *)(param_1 + 0x14);
      if (param_3 == (byte *)0x0) {
        uStack_2c._0_1_ = (byte)uStack_2c | 2;
        iVar1 = zcl_cluster_fragment_is_supported();
        uStack_2c._0_1_ = (byte)uStack_2c & 0xf3 | (byte)(iVar1 << 2) & 0xc;
        uVar2 = 0;
      }
      else {
        uStack_2c._0_1_ = (byte)uStack_2c & 0xf0 | *param_3 & 0xf;
        uVar2 = *param_3 >> 4 & 1;
      }
      uStack_2c = CONCAT31(uStack_2c._1_3_,(byte)(uVar2 << 4) | (byte)uStack_2c & 0xef);
      if (param_2 == (undefined4 *)0x0) {
        uStack_28 = 0;
        uStack_24 = 0;
      }
      else {
        uStack_28 = *param_2;
        uStack_24 = param_2[1];
      }
      af_data_request(&uStack_44);
      uVar4 = err_to_zcl_status();
    }
  }
  return uVar4;
}

