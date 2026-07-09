/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_common.o -> zcl_cmd_to_packet
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
zcl_cmd_to_packet(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 in_stack_00000000;
  undefined1 in_stack_00000004;
  undefined1 *in_stack_00000008;
  undefined2 in_stack_0000000c;
  undefined4 in_stack_00000010;
  char in_stack_00000014;
  
  if (param_1 == 0) {
    uVar3 = 2;
  }
  else {
    iVar2 = af_get_ep_desc(in_stack_00000000);
    if ((iVar2 == 0) ||
       (((uVar1 = *(undefined2 *)(iVar2 + 2), in_stack_00000014 != '\0' &&
         (iVar2 = af_endpoint_is_gateway(in_stack_00000000), iVar2 == 0)) &&
        (iVar2 = zcl_get_cluster_desc(in_stack_00000000,param_8,(param_4 == 0) + '\x01'), iVar2 == 0
        )))) {
      uVar3 = 5;
    }
    else {
      zcl_packet_setup_header(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      zcl_packet_setup_stamp
                (param_1,in_stack_00000000,in_stack_00000004,param_8,uVar1,*in_stack_00000008,
                 in_stack_00000008 + 2);
      zcl_packet_add_payload(param_1,in_stack_0000000c,in_stack_00000010);
      uVar3 = 0;
    }
  }
  return uVar3;
}

