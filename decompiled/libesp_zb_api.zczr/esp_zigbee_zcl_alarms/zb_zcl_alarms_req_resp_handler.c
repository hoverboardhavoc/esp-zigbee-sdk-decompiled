/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_alarms.o -> zb_zcl_alarms_req_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */

int zb_zcl_alarms_req_resp_handler(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *__src;
  undefined1 *puVar5;
  char *pcVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined1 *puVar9;
  undefined1 uVar10;
  char cVar11;
  undefined2 uVar12;
  undefined4 uStack_44;
  uint uStack_40;
  undefined4 uStack_3c;
  undefined1 auStack_3b [3];
  undefined4 uStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  uint uStack_2c;
  
  iVar2 = zb_buf_get_tail_func(0x1b);
  if (((param_1 != 0) && (iVar2 != 0)) && (iVar3 = esp_zb_has_core_action_handler(), iVar3 != 0)) {
    if ((*(char *)(iVar2 + 0x14) == '\0') &&
       (iVar4 = esp_zb_zcl_get_cluster(*(undefined1 *)(iVar2 + 0xc),9,1), iVar4 != 0)) {
      if (*(char *)(iVar2 + 0x13) == '\x02') {
        memset(&stack0xffffffc4,0,0x1b);
        iVar2 = zb_buf_get_tail_func(param_1,0x1b);
        uVar10 = *(undefined1 *)(iVar2 + 0xc);
        __src = (void *)zb_buf_get_tail_func(param_1,0x1b);
        memcpy(&stack0xffffffc4,__src,0x1b);
        puVar5 = (undefined1 *)alarms_alarm_table_pop_earliest_entry(uVar10);
        if (puVar5 == (undefined1 *)0x0) {
          uVar7 = 0;
          uVar12 = 0;
          cVar11 = -0x75;
          uVar10 = 0;
        }
        else {
          uVar10 = *puVar5;
          uVar12 = *(undefined2 *)(puVar5 + 2);
          uVar7 = *(undefined4 *)(puVar5 + 4);
          cVar11 = '\0';
          free(puVar5);
        }
        zb_buf_reuse_func(param_1);
        puVar5 = (undefined1 *)zb_buf_reuse_func(param_1);
        *puVar5 = 0x19;
        pcVar6 = (char *)zb_zcl_get_ctx();
        cVar1 = *pcVar6;
        puVar9 = puVar5 + 4;
        *pcVar6 = cVar1 + '\x01';
        puVar5[1] = cVar1;
        puVar5[2] = 1;
        puVar5[3] = cVar11;
        if (cVar11 == '\0') {
          puVar5[4] = uVar10;
          zb_put_next_htole16(puVar5 + 5,uVar12);
          puVar9 = (undefined1 *)zb_put_next_htole32(uVar7);
        }
        zb_zcl_finish_and_send_packet
                  (param_1,puVar9,auStack_3b,2,uStack_34._3_1_,uStack_30 & 0xff,
                   uStack_2c >> 8 & 0xffff,9);
        return iVar3;
      }
      if (*(char *)(iVar2 + 0x13) == '\x03') {
        iVar2 = zb_buf_get_tail_func(param_1,0x1b);
        alarms_alarm_table_free(*(undefined1 *)(iVar2 + 0xc));
        uVar7 = zb_buf_get_tail_func(param_1,0x1b);
        uVar10 = 0;
_L0:
        zb_zcl_send_default_handler(param_1,uVar7,uVar10);
        return iVar3;
      }
    }
    else if ((*(char *)(iVar2 + 0x14) == '\x01') &&
            ((iVar4 = esp_zb_zcl_get_cluster(*(undefined1 *)(iVar2 + 0xc),9,2), iVar4 != 0 &&
             (*(char *)(iVar2 + 0x13) == '\x01')))) {
      uStack_40 = 0;
      uStack_3c = 0;
      uStack_38 = 0;
      uStack_34 = 0;
      uStack_30 = 0;
      iVar2 = zb_buf_get_tail_func(param_1,0x1b);
      uStack_38 = CONCAT31(uStack_38._1_3_,*(undefined1 *)(iVar2 + 0xc));
      uStack_38 = CONCAT22(9,(undefined2)uStack_38);
      iVar2 = zb_buf_len_func(param_1);
      uVar10 = 0x80;
      if (iVar2 != 0) {
        pcVar6 = (char *)zb_buf_begin_func(param_1);
        cVar11 = *pcVar6;
        uStack_44 = 0;
        uVar8 = zb_buf_len_func(param_1);
        if (7 < uVar8) {
          uStack_44 = CONCAT13(pcVar6[3],CONCAT12(pcVar6[2],CONCAT11(pcVar6[1],cVar11)));
          memcpy(&uStack_40,pcVar6 + 4,4);
        }
        uStack_34 = CONCAT31(uStack_34._1_3_,cVar11);
        if (cVar11 == '\0') {
          uStack_34 = uStack_44 & 0xffffff00;
          uStack_30 = uStack_40;
        }
        iVar2 = esp_zb_core_action_handler_schedule(0x53,&stack0xffffffc4);
        uVar10 = iVar2 != 0;
      }
      uVar7 = zb_buf_get_tail_func(param_1,0x1b);
      goto _L0;
    }
  }
  return 0;
}

