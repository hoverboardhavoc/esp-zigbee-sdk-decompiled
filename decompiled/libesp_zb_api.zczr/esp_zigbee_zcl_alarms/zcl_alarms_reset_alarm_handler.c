/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_alarms.o -> zcl_alarms_reset_alarm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_alarms_reset_alarm_handler(undefined4 param_1)

{
  char cVar1;
  short sVar2;
  undefined1 uVar3;
  char *pcVar4;
  char *__ptr;
  int iVar5;
  int iVar6;
  undefined4 uStack_2c;
  undefined1 uStack_28;
  undefined2 uStack_26;
  char cStack_24;
  undefined2 uStack_22;
  
  iVar5 = zb_buf_get_tail_func(0x38);
  pcVar4 = *(char **)(iVar5 + 0x10);
  uStack_2c = 0;
  iVar5 = zb_buf_get_tail_func(param_1,0x38);
  uStack_28 = *(undefined1 *)(iVar5 + 4);
  uStack_26 = 9;
  cStack_24 = *pcVar4;
  uStack_22 = *(undefined2 *)(pcVar4 + 1);
  esp_zb_core_action_handler_schedule(0x50,&uStack_2c);
  iVar5 = esp_err_to_zb_ret();
  uVar3 = uStack_28;
  if (iVar5 == 0) {
    sVar2 = *(short *)(pcVar4 + 1);
    cVar1 = *pcVar4;
    pcVar4 = (char *)alarms_get_alarm_table(uStack_28);
    if (pcVar4 != (char *)0x0) {
      while (__ptr = *(char **)pcVar4, __ptr != (char *)0x0) {
        if ((*__ptr == cVar1) && (*(short *)(__ptr + 2) == sVar2)) {
          *(undefined4 *)pcVar4 = *(undefined4 *)(__ptr + 8);
          alarms_dec_alarm_count(uVar3);
          free(__ptr);
          break;
        }
        pcVar4 = __ptr + 8;
      }
    }
  }
  iVar6 = zb_buf_get_tail_func(param_1,0x38);
  *(int *)(iVar6 + 8) = iVar5;
  return iVar5;
}

