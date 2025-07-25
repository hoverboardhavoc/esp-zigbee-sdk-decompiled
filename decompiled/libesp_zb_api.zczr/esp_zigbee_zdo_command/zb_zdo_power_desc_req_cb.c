/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zdo_command.o -> zb_zdo_power_desc_req_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zdo_power_desc_req_cb(int param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  code *pcVar5;
  undefined4 uStack_28;
  ushort uStack_24;
  
  if (param_1 == 0) {
    param_1 = zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_zdo_command.c"
                        ,0x289);
  }
  uStack_28 = 0;
  uStack_24 = 0;
  puVar2 = (undefined1 *)zb_buf_begin_func();
  uVar1 = *puVar2;
  zb_schedule_alarm_cancel(power_desc_req_timeout,uVar1,0);
  iVar3 = esp_zb_zdo_callback_find(uVar1);
  if ((iVar3 != 0) && (*(short *)(iVar3 + 2) == 3)) {
    pcVar5 = *(code **)(iVar3 + 4);
    uVar4 = *(undefined4 *)(iVar3 + 8);
    esp_zb_zdo_callback_remove(uVar1);
    if (pcVar5 != (code *)0x0) {
      uStack_28 = CONCAT31(uStack_28._1_3_,puVar2[1]);
      if (puVar2[1] == '\0') {
        uStack_28 = CONCAT13(puVar2[3],CONCAT12(puVar2[2],(undefined2)uStack_28));
        uStack_24 = (ushort)(byte)puVar2[5] << 8 & 0xf000 |
                    (ushort)(byte)puVar2[4] | (ushort)(byte)puVar2[5] << 8 & 0xf00;
      }
      (*pcVar5)(&uStack_28,uVar4);
    }
  }
  zb_buf_free_func(param_1);
  return;
}

