/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> electrical_measurement.o -> ezb_zcl_electrical_meas_get_meas_prof_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_electrical_meas_get_meas_prof_cmd_req(void *param_1)

{
  int iVar1;
  undefined1 auStack_50 [20];
  undefined4 uStack_3c;
  undefined1 auStack_38 [36];
  undefined4 uStack_14;
  
  memset(auStack_38,0,0x28);
  if (param_1 == (void *)0x0) {
    iVar1 = -1;
  }
  else {
    iVar1 = zcl_packet_init(auStack_38,0);
    if (iVar1 == 0) {
      memcpy(auStack_50,param_1,10);
      iVar1 = zcl_cmd_to_packet(auStack_38,1,0,0,*(undefined1 *)((int)param_1 + 0xc),0,1,0xb04);
      if (iVar1 == 0) {
        uStack_3c = CONCAT22(uStack_3c._2_2_,*(undefined2 *)((int)param_1 + 0x18));
        iVar1 = zmsg_append_bytes(uStack_14,2,&uStack_3c);
        if (iVar1 == 0) {
          uStack_3c = *(undefined4 *)((int)param_1 + 0x1c);
          iVar1 = zmsg_append_bytes(uStack_14,4,&uStack_3c);
          if (iVar1 == 0) {
            uStack_3c = CONCAT31(uStack_3c._1_3_,*(undefined1 *)((int)param_1 + 0x20));
            iVar1 = zmsg_append_bytes(uStack_14,1,&uStack_3c);
            if (iVar1 == 0) {
              zcl_packet_send(auStack_38,(int)param_1 + 0x10);
              iVar1 = zcl_status_to_err();
              if (iVar1 == 0) {
                return 0;
              }
            }
          }
        }
      }
    }
  }
  zcl_packet_free(auStack_38);
  return iVar1;
}

