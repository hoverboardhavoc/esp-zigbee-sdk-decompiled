/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app.o -> nwk_nlme_event_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_nlme_event_indication(nwk_nlme_event_ind_t *ind)

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
  undefined4 uStack_24;
  zdo_app_signal_t signal;
  
  uStack_24 = 0;
  signal.signal = 0;
  signal.parameters[0] = '\0';
  signal.parameters[1] = '\0';
  signal.parameters[2] = '\0';
  signal.parameters[3] = '\0';
  signal.parameters[4] = '\0';
  signal.parameters[5] = '\0';
  signal.parameters[6] = '\0';
  signal.parameters[7] = '\0';
  signal.parameters[8] = '\0';
  signal.parameters[9] = '\0';
  signal.parameters[10] = '\0';
  signal.parameters[0xb] = '\0';
  if (ind->event == '\0') {
    signal._0_4_ = *(undefined4 *)((int)&ind->field_1 + 2);
    uStack_24._0_3_ = CONCAT12((ind->field_1).network_status.status,0x203);
    uStack_24 = CONCAT13(*(undefined1 *)((int)&ind->field_1 + 1),(uint3)uStack_24);
  }
  else {
    if (ind->event != '\x01') {
      uVar4 = 0x28;
      uVar3 = 0x260;
      uVar1 = __assert_func("//build/esp-zigbee/src/core/zdo/zdo_app.c",0x81);
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
    uStack_24._0_3_ = CONCAT12((ind->field_1).network_status.status,0x204);
    uStack_24 = (uint)(uint3)uStack_24;
  }
  zdo_app_put_signal(&uStack_24);
  return;
}

