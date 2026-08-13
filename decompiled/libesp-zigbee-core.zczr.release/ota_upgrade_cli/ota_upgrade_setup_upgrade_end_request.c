/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_cli.o -> ota_upgrade_setup_upgrade_end_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ota_upgrade_setup_upgrade_end_request(int param_1,int param_2,int param_3,undefined1 param_4)

{
  int unaff_s0;
  int unaff_s1;
  int iVar1;
  int unaff_s2;
  undefined4 auStack_24 [4];
  
  if ((param_1 == 0) || (unaff_s2 = param_2, param_3 == 0)) {
    __assert_func(0,0,0,0);
  }
  else {
    iVar1 = zcl_packet_setup_response_with_extension(param_3,6,1,0);
    if (iVar1 != 0) {
      return iVar1;
    }
    auStack_24[0] = CONCAT31(auStack_24[0]._1_3_,param_4);
    iVar1 = zmsg_append_bytes(*(undefined4 *)(param_1 + 0x24),1,auStack_24);
    unaff_s1 = 0;
    unaff_s0 = param_1;
    if (iVar1 != 0) {
      return 0x89;
    }
  }
  iVar1 = zmsg_append_le16(*(undefined4 *)(unaff_s0 + 0x24),**(undefined2 **)(unaff_s2 + 0x1c));
  if ((iVar1 == 0) &&
     (iVar1 = zmsg_append_le16(*(undefined4 *)(unaff_s0 + 0x24),**(undefined2 **)(unaff_s2 + 0x20)),
     iVar1 == 0)) {
    auStack_24[0] = *(undefined4 *)(unaff_s2 + 0x2c);
    iVar1 = zmsg_append_bytes(*(undefined4 *)(unaff_s0 + 0x24),4,auStack_24);
    if (iVar1 == 0) {
      return unaff_s1;
    }
  }
  return 0x89;
}

