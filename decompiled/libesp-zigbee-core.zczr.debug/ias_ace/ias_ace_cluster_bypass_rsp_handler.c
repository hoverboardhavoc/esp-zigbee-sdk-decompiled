/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_bypass_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ias_ace_cluster_bypass_rsp_handler(int param_1,int param_2,size_t param_3)

{
  int iVar1;
  uint uVar2;
  size_t unaff_s2;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  uint uStack_20;
  void *pvStack_1c;
  uint uStack_18;
  ushort uStack_12;
  
  uStack_12 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  iStack_24 = 0;
  uStack_20 = 0;
  pvStack_1c = (void *)0x0;
  uStack_18 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0x297,
                  "ias_ace_cluster_bypass_rsp_handler","packet && rsp");
  }
  else {
    iVar1 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_12,&uStack_20);
    param_3 = 1;
    if (iVar1 != 1) {
      uVar2 = 0x80;
      goto _L0;
    }
    unaff_s2 = uStack_20 & 0xff;
    if (unaff_s2 == 0) {
      uVar2 = 0x87;
      goto _L0;
    }
  }
  pvStack_1c = calloc(param_3,unaff_s2);
  if (pvStack_1c == (void *)0x0) {
    uVar2 = 0x89;
  }
  else {
    af_read_bytes(*(undefined4 *)(param_1 + 0x24),&uStack_12,unaff_s2,pvStack_1c);
    uVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uVar2 < uStack_12) {
      uVar2 = 0x80;
    }
    else {
      uVar2 = zcl_packet_to_message(&uStack_2c,param_1);
      if (uVar2 == 0) {
        uStack_18 = CONCAT31(uStack_18._1_3_,0xfe);
        iStack_24 = param_1;
        zcl_core_action_schedule(0x2b,&uStack_2c);
        if ((uStack_18 & 0xff) != 0xfe) {
          uVar2 = uStack_18 & 0xff;
        }
      }
    }
  }
_L0:
  if (pvStack_1c != (void *)0x0) {
    mm_free();
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar2);
  return;
}

