/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_secur.o -> zdo_tc_put_device_authorized_signal
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_tc_put_device_authorized_signal(undefined4 *param_1,undefined1 param_2,undefined1 param_3)

{
  undefined4 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined2 uStack_24;
  
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_34 = 8;
  puVar4 = (undefined1 *)zdo_app_signal_get_params(&uStack_34);
  uVar1 = *param_1;
  uVar2 = *(undefined2 *)(param_1 + 1);
  uVar3 = param_1[1];
  *puVar4 = (char)*(undefined2 *)param_1;
  puVar4[1] = (char)((uint)uVar1 >> 8);
  puVar4[2] = (char)((uint)uVar1 >> 0x10);
  puVar4[3] = (char)((uint)uVar1 >> 0x18);
  puVar4[4] = (char)uVar2;
  puVar4[5] = (char)((uint)uVar3 >> 8);
  puVar4[6] = (char)((uint)uVar3 >> 0x10);
  puVar4[7] = (char)((uint)uVar3 >> 0x18);
  *(undefined2 *)(puVar4 + 8) = 0xffff;
  nwk_address_short_by_extended(param_1,puVar4 + 8);
  puVar4[10] = param_2;
  puVar4[0xb] = param_3;
  zdo_app_put_signal(&uStack_34);
  return;
}

