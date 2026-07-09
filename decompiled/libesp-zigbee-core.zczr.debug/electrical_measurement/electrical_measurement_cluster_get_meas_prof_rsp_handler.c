/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> electrical_measurement.o -> electrical_measurement_cluster_get_meas_prof_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void electrical_measurement_cluster_get_meas_prof_rsp_handler(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  void *pvStack_1c;
  uint uStack_18;
  ushort uStack_12;
  
  uStack_12 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  iStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  pvStack_1c = (void *)0x0;
  uStack_18 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/electrical_measurement.c"
                  ,0xc6,"electrical_measurement_cluster_get_meas_prof_rsp_handler","packet && rsp");
  }
  else {
    af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_12,&uStack_28);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_12,&uStack_24);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_12,(int)&uStack_24 + 1);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_12,(int)&uStack_24 + 2);
    af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_12,&uStack_20);
    uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uStack_12 <= uVar1) {
      if ((uStack_24 >> 0x10 & 0xff) != 0) {
        iVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
        uVar1 = iVar2 - (uint)uStack_12 & 0xffff;
        pvStack_1c = calloc(uVar1,1);
        if (pvStack_1c == (void *)0x0) {
          uVar1 = 0x89;
          goto _L0;
        }
        af_read_bytes(*(undefined4 *)(param_1 + 0x24),&uStack_12,uVar1,pvStack_1c);
      }
      uVar1 = zcl_packet_to_message(&uStack_34,param_1);
      if (uVar1 == 0) {
        uStack_18 = CONCAT31(uStack_18._1_3_,0xfe);
        iStack_2c = param_1;
        zcl_core_action_schedule(0x42,&uStack_34);
        if ((uStack_18 & 0xff) != 0xfe) {
          uVar1 = uStack_18 & 0xff;
        }
      }
      goto _L0;
    }
  }
  uVar1 = 0x80;
_L0:
  if (pvStack_1c != (void *)0x0) {
    mm_free();
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar1);
  return;
}

