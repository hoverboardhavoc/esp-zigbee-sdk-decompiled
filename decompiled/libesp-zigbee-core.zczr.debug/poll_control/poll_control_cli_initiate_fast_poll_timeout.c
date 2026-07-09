/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_cli_initiate_fast_poll_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint poll_control_cli_initiate_fast_poll_timeout(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined2 *extraout_a1;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar5 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/poll_control.c"
                          ,0x20a,"poll_control_cli_initiate_fast_poll_timeout",&_LC8);
    uStack_40 = 0;
    uStack_3c = 0;
    uStack_38 = 0;
    uStack_34 = 0;
    uVar4 = zcl_packet_to_message(&uStack_40,uVar5);
    uVar3 = uVar4;
    if (uVar4 == 0) {
      uStack_34 = CONCAT31(uStack_34._1_3_,0xfe);
      uStack_38 = uVar5;
      zcl_core_action_schedule(0x3e,&uStack_40);
      uVar3 = uStack_34 & 0xff;
      if ((uVar3 == 0xfe) || (uVar4 = uVar3, uVar3 == 0)) {
        uVar3 = uVar4;
        *extraout_a1 = uStack_34._2_2_;
      }
    }
    return uVar3;
  }
  puVar1 = (undefined4 *)calloc(1,0x28);
  pvVar2 = calloc(1,0x10);
  uVar11 = param_1[1];
  uVar10 = param_1[2];
  uVar5 = param_1[3];
  uVar6 = param_1[4];
  uVar7 = param_1[5];
  uVar8 = param_1[6];
  uVar9 = param_1[7];
  *puVar1 = *param_1;
  puVar1[1] = uVar11;
  puVar1[2] = uVar10;
  puVar1[3] = uVar5;
  puVar1[4] = uVar6;
  puVar1[5] = uVar7;
  puVar1[6] = uVar8;
  puVar1[7] = uVar9;
  *(undefined2 *)(puVar1 + 8) = *(undefined2 *)(param_1 + 8);
  puVar1[9] = pvVar2;
  milli_timer_init(poll_control_cli_stop_fast_poll,puVar1);
  uVar3 = milli_timer_start(pvVar2,param_2);
  return uVar3;
}

