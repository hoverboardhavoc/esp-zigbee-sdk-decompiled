/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zdo_command.o -> zb_zdo_nwk_update_req_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zdo_nwk_update_req_cb(int param_1)

{
  undefined1 uVar1;
  code *pcVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [4];
  undefined1 uStack_30;
  undefined1 uStack_2f;
  undefined1 uStack_2e;
  undefined1 uStack_2d;
  undefined1 uStack_2c;
  undefined1 auStack_2b [27];
  
  if (param_1 == 0) {
    param_1 = zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_zdo_command.c"
                        ,0x4b4);
  }
  memset(auStack_38,0,0x28);
  puVar3 = (undefined1 *)zb_buf_begin_func(param_1);
  auStack_38[0] = puVar3[1];
  uVar1 = *puVar3;
  memcpy(auStack_34,puVar3 + 2,4);
  uStack_30 = puVar3[6];
  uStack_2f = puVar3[7];
  uStack_2e = puVar3[8];
  uStack_2d = puVar3[9];
  uStack_2c = puVar3[10];
  memcpy(auStack_2b,puVar3 + 0xb,0x1b);
  zb_schedule_alarm_cancel(nwk_update_req_timeout,uVar1,0);
  iVar4 = esp_zb_zdo_callback_find(uVar1);
  if ((iVar4 != 0) && (*(short *)(iVar4 + 2) == 0x38)) {
    pcVar2 = *(code **)(iVar4 + 4);
    uVar5 = *(undefined4 *)(iVar4 + 8);
    esp_zb_zdo_callback_remove(uVar1);
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(auStack_38,uVar5);
    }
  }
  zb_buf_free_func(param_1);
  return;
}

