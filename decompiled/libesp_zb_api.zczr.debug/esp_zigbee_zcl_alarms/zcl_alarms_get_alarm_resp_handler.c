/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_alarms.o -> zcl_alarms_get_alarm_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_alarms_get_alarm_resp_handler(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined4 uStack_28;
  undefined4 uStack_24;
  uint uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  iVar2 = zb_buf_get_tail_func(0x1b);
  uStack_24 = CONCAT31(uStack_24._1_3_,*(undefined1 *)(iVar2 + 0xc));
  uStack_24 = CONCAT22(9,(undefined2)uStack_24);
  iVar2 = zb_buf_len_func(param_1);
  if (iVar2 == 0) {
    uVar1 = 0x80;
  }
  else {
    puVar4 = (undefined1 *)zb_buf_begin_func(param_1);
    uStack_18 = CONCAT31(uStack_18._1_3_,*puVar4);
    uVar5 = zb_buf_len_func(param_1);
    if (7 < uVar5) {
      uStack_18 = CONCAT13(puVar4[3],CONCAT12(puVar4[2],CONCAT11(puVar4[1],(undefined1)uStack_18)));
      uStack_14 = *(undefined4 *)(puVar4 + 4);
    }
    uStack_20 = CONCAT31(uStack_20._1_3_,(undefined1)uStack_18);
    if ((uStack_18 & 0xff) == 0) {
      uStack_20 = uStack_18;
      uStack_1c = uStack_14;
    }
    iVar2 = esp_zb_core_action_handler_schedule(0x53,&uStack_28);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  uVar3 = zb_buf_get_tail_func(param_1,0x1b);
  zb_zcl_send_default_handler(param_1,uVar3,uVar1);
  return 1;
}

