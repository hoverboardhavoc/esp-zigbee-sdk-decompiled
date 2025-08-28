/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zdo_command.o -> simple_desc_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void simple_desc_cb(int param_1)

{
  undefined1 uVar1;
  undefined1 *__ptr;
  char cVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  code *pcVar6;
  
  puVar3 = (undefined1 *)zb_buf_begin_func();
  uVar1 = *puVar3;
  zb_schedule_alarm_cancel(simple_desc_req_timeout,uVar1,0);
  iVar4 = esp_zb_zdo_callback_find(uVar1);
  if (iVar4 != 0) {
    if (*(short *)(iVar4 + 2) == 4) {
      pcVar6 = *(code **)(iVar4 + 4);
      uVar5 = *(undefined4 *)(iVar4 + 8);
      esp_zb_zdo_callback_remove(uVar1);
      if (pcVar6 != (code *)0x0) {
        cVar2 = puVar3[1];
        if (cVar2 == '\0') {
          __ptr = (undefined1 *)calloc(1,0xc);
          if (__ptr == (undefined1 *)0x0) {
            cVar2 = -0x76;
          }
          else {
            uVar1 = puVar3[9];
            __ptr[3] = puVar3[8];
            __ptr[4] = uVar1;
            __ptr[5] = __ptr[5] & 0xf0 | puVar3[10] & 0xf;
            __ptr[6] = puVar3[0xb];
            __ptr[7] = puVar3[0xc];
            uVar1 = puVar3[7];
            __ptr[1] = puVar3[6];
            __ptr[2] = uVar1;
            *__ptr = puVar3[5];
            puVar3 = puVar3 + 0xd;
            __ptr[8] = (char)puVar3;
            __ptr[9] = (char)((uint)puVar3 >> 8);
            __ptr[10] = (char)((uint)puVar3 >> 0x10);
            __ptr[0xb] = (char)((uint)puVar3 >> 0x18);
          }
        }
        else {
          __ptr = (undefined1 *)0x0;
        }
        (*pcVar6)(cVar2,__ptr,uVar5);
        if (__ptr != (undefined1 *)0x0) {
          free(__ptr);
        }
      }
    }
    else {
      uVar5 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_API_ZDO",&_L0,uVar5,"ESP_ZIGBEE_API_ZDO",
                    *(undefined2 *)(iVar4 + 2),uVar1);
    }
  }
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  return;
}

