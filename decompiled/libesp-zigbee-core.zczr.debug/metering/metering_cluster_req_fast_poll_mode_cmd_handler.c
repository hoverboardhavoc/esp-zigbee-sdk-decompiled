/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> metering.o -> metering_cluster_req_fast_poll_mode_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 metering_cluster_req_fast_poll_mode_cmd_handler(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uStack_34;
  ushort uStack_2e;
  uint auStack_2c [4];
  uint uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  auStack_2c[0] = 0;
  auStack_2c[1] = 0;
  auStack_2c[2] = 0;
  auStack_2c[3] = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_2e = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/metering.c",0x135,
                  "metering_cluster_req_fast_poll_mode_cmd_handler","packet && rsp");
  }
  else {
    iVar3 = af_read_bytes(*(undefined4 *)(param_1 + 0x24),&uStack_2e,2,auStack_2c + 3);
    if (iVar3 == 0) {
      uVar2 = 0x80;
      goto _L0;
    }
  }
  uVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  if (uVar2 < uStack_2e) {
    uVar2 = 0x80;
  }
  else {
    uVar2 = zcl_packet_to_message(auStack_2c,param_1);
    if (uVar2 == 0) {
      uStack_1c = CONCAT31(uStack_1c._1_3_,0xfe);
      auStack_2c[2] = param_1;
      zcl_core_action_schedule(0x45,auStack_2c);
      uVar1 = uStack_1c & 0xff;
      if ((uStack_1c & 0xff) == 0xfe) {
        uVar1 = uVar2;
      }
      uVar2 = uVar1;
      if ((auStack_2c[0] & 0xff) == 0xfe) {
        uVar2 = 1;
      }
      else if (uVar2 == 0) {
        uStack_34 = CONCAT31(uStack_34._1_3_,(undefined1)uStack_18);
        iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_34);
        if (iVar3 == 0) {
          uStack_34 = uStack_14;
          iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),4,&uStack_34);
          if (iVar3 == 0) {
            uVar2 = zcl_packet_setup_response(param_2,param_1,3);
            if (uVar2 == 0) {
              return 0;
            }
          }
          else {
            uVar2 = 0x89;
          }
        }
        else {
          uVar2 = 0x89;
        }
      }
    }
  }
_L0:
  uVar4 = zcl_packet_setup_default_response(param_2,param_1,uVar2);
  return uVar4;
}

