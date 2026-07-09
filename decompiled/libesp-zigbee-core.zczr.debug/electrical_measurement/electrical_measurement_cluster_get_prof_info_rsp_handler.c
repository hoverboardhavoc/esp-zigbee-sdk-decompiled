/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> electrical_measurement.o -> electrical_measurement_cluster_get_prof_info_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void electrical_measurement_cluster_get_prof_info_rsp_handler(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint __nmemb;
  ushort uStack_3a;
  undefined4 uStack_38;
  undefined4 uStack_34;
  int iStack_30;
  undefined4 uStack_2c;
  void *pvStack_28;
  uint uStack_24;
  
  uStack_38 = 0;
  uStack_34 = 0;
  iStack_30 = 0;
  uStack_2c = 0;
  pvStack_28 = (void *)0x0;
  uStack_24 = 0;
  uStack_3a = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/electrical_measurement.c"
                  ,0xa6,"electrical_measurement_cluster_get_prof_info_rsp_handler","packet && rsp");
  }
  else {
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_3a,&uStack_2c);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_3a,(int)&uStack_2c + 1);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_3a,(int)&uStack_2c + 2);
    uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uVar1 < uStack_3a) {
      uVar1 = 0x80;
      goto _L0;
    }
  }
  iVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  uVar1 = iVar2 - (uint)uStack_3a >> 1;
  __nmemb = uVar1 & 0xffff;
  if ((uVar1 & 0xffff) != 0) {
    pvStack_28 = calloc(__nmemb,2);
    if (pvStack_28 == (void *)0x0) {
      uVar1 = 0x89;
      goto _L0;
    }
    for (uVar1 = 0; uVar1 < __nmemb; uVar1 = uVar1 + 1 & 0xffff) {
      af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_3a,(void *)((int)pvStack_28 + uVar1 * 2))
      ;
    }
  }
  uVar1 = zcl_packet_to_message(&uStack_38,param_1);
  if (uVar1 == 0) {
    uStack_24 = CONCAT31(uStack_24._1_3_,0xfe);
    iStack_30 = param_1;
    zcl_core_action_schedule(0x41,&uStack_38);
    if ((uStack_24 & 0xff) != 0xfe) {
      uVar1 = uStack_24 & 0xff;
    }
  }
_L0:
  if (pvStack_28 != (void *)0x0) {
    mm_free();
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar1);
  return;
}

