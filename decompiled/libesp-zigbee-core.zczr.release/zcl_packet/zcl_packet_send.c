/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010730) */
/* WARNING: Removing unreachable block (ram,0x0001078c) */

undefined4 zcl_packet_send(int param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uStack_44;
  undefined1 auStack_40 [10];
  undefined2 uStack_36;
  undefined2 uStack_34;
  undefined2 uStack_32;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  if (param_1 != 0) {
    zcl_frame_fill_header_isra_0();
    uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    uVar2 = zcl_packet_max_available_space
                      (*(undefined2 *)(param_1 + 0x16),0,*(ushort *)(param_1 + 0x1a) >> 2 & 1);
    uVar3 = 0x89;
    if (uVar1 <= uVar2) {
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
      uStack_2c._0_1_ = (byte)uStack_2c | 2;
      iVar4 = zcl_cluster_fragment_is_supported();
      uStack_2c = CONCAT31(uStack_2c._1_3_,(byte)uStack_2c & 0xf3 | (byte)(iVar4 << 2) & 0xc) &
                  0xffffffef;
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
    return uVar3;
  }
  return 1;
}

