/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app.o -> nwk_nlme_event_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_nlme_event_indication(char *param_1)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  undefined4 extraout_a1;
  undefined2 uVar3;
  undefined1 uVar4;
  undefined2 uStack_68;
  undefined2 uStack_66;
  undefined2 uStack_64;
  undefined2 uStack_62;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined2 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  if (*param_1 == '\0') {
    uStack_28 = *(undefined4 *)(param_1 + 4);
    uStack_2c._0_3_ = CONCAT12(param_1[2],0x203);
    uStack_2c = CONCAT13(param_1[3],(uint3)uStack_2c);
    if (param_1[2] == '\x10') {
      uStack_18 = 0;
      uStack_14 = 0;
      zdo_device_annce_req(&uStack_18);
    }
  }
  else {
    if (*param_1 != '\x01') {
      uVar4 = 0x28;
      uVar3 = 0x288;
      uVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_app.c",0x8d);
      uStack_50 = 0;
      uStack_4c = 0;
      uStack_48 = 0;
      uStack_44 = 0;
      uStack_54 = 5;
      puVar2 = (undefined2 *)zdo_app_signal_get_params(&uStack_54);
      *puVar2 = uVar3;
      uStack_68 = (undefined2)uVar1;
      uStack_66 = (undefined2)((uint)uVar1 >> 0x10);
      uStack_64 = (undefined2)extraout_a1;
      uStack_62 = (undefined2)((uint)extraout_a1 >> 0x10);
      puVar2[1] = uStack_68;
      puVar2[2] = uStack_66;
      puVar2[3] = uStack_64;
      puVar2[4] = uStack_62;
      *(undefined1 *)(puVar2 + 5) = uVar4;
      zdo_app_put_signal(&uStack_54);
      return;
    }
    uStack_2c._0_3_ = CONCAT12(param_1[2],0x204);
    uStack_2c = (uint)(uint3)uStack_2c;
  }
  zdo_app_put_signal(&uStack_2c);
  return;
}

