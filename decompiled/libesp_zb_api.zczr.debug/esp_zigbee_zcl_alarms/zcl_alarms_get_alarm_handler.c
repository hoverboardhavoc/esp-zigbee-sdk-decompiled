/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_alarms.o -> zcl_alarms_get_alarm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_alarms_get_alarm_handler(undefined4 param_1)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  void *__src;
  undefined1 *puVar4;
  char *pcVar5;
  undefined1 *puVar6;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  uint uStack_24;
  uint uStack_20;
  uint uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  undefined1 uStack_12;
  
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_12 = 0;
  uStack_30 = 0;
  iVar3 = zb_buf_get_tail_func(0x1b);
  uVar1 = *(undefined1 *)(iVar3 + 0xc);
  __src = (void *)zb_buf_get_tail_func(param_1,0x1b);
  memcpy(&uStack_2c,__src,0x1b);
  puVar4 = (undefined1 *)alarms_alarm_table_pop_earliest_entry(uVar1);
  if (puVar4 == (undefined1 *)0x0) {
    uStack_34 = 0x8b;
  }
  else {
    uStack_34 = (uint)CONCAT21(*(undefined2 *)(puVar4 + 2),*puVar4) << 8;
    uStack_30 = *(undefined4 *)(puVar4 + 4);
    free(puVar4);
  }
  zb_buf_reuse_func(param_1);
  puVar4 = (undefined1 *)zb_buf_reuse_func(param_1);
  *puVar4 = 0x19;
  pcVar5 = (char *)zb_zcl_get_ctx();
  cVar2 = *pcVar5;
  *pcVar5 = cVar2 + '\x01';
  puVar4[1] = cVar2;
  puVar4[2] = 1;
  puVar4[3] = (char)uStack_34;
  puVar6 = puVar4 + 4;
  if ((char)uStack_34 == '\0') {
    puVar4[4] = uStack_34._1_1_;
    zb_put_next_htole16(puVar4 + 5,uStack_34 >> 0x10);
    puVar6 = (undefined1 *)zb_put_next_htole32(uStack_30);
  }
  zb_zcl_finish_and_send_packet
            (param_1,puVar6,(int)&uStack_2c + 1,2,uStack_24 >> 0x18,uStack_20 & 0xff,
             uStack_1c >> 8 & 0xffff,9);
  return 1;
}

