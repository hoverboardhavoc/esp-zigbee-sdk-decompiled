/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
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
  undefined1 *extraout_a1;
  undefined4 uVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_34;
  
  if (param_1 == (undefined4 *)0x0) {
    pcVar7 = __func___0;
    uVar5 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/poll_control.c"
                          ,0x214,&_LC8);
    uStack_50 = 0;
    uStack_4c = 0;
    uStack_48 = 0;
    uStack_44 = 0;
    uStack_34 = param_2;
    uVar4 = zcl_packet_to_message(&uStack_50,uVar5);
    uVar3 = uVar4;
    if (uVar4 == 0) {
      uStack_44 = CONCAT31(uStack_44._1_3_,0xfe);
      uStack_48 = uVar5;
      zcl_core_action_schedule(0x3e,&uStack_50);
      uVar3 = uStack_44 & 0xff;
      if ((uVar3 == 0xfe) || (uVar4 = uVar3, uVar3 == 0)) {
        uVar3 = uVar4;
        *extraout_a1 = uStack_44._1_1_;
        *(undefined2 *)pcVar7 = uStack_44._2_2_;
      }
    }
    return uVar3;
  }
  puVar1 = (undefined4 *)calloc(1,0x28);
  pvVar2 = calloc(1,0x10);
  uVar12 = param_1[1];
  uVar11 = param_1[2];
  uVar5 = param_1[3];
  uVar6 = param_1[4];
  uVar8 = param_1[5];
  uVar9 = param_1[6];
  uVar10 = param_1[7];
  *puVar1 = *param_1;
  puVar1[1] = uVar12;
  puVar1[2] = uVar11;
  puVar1[3] = uVar5;
  puVar1[4] = uVar6;
  puVar1[5] = uVar8;
  puVar1[6] = uVar9;
  puVar1[7] = uVar10;
  *(undefined2 *)(puVar1 + 8) = *(undefined2 *)(param_1 + 8);
  puVar1[9] = pvVar2;
  milli_timer_init(poll_control_cli_stop_fast_poll,puVar1);
  uVar3 = milli_timer_start(pvVar2,param_2);
  return uVar3;
}

