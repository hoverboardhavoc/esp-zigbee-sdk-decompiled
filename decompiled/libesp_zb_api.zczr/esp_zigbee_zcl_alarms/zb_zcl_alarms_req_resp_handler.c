/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_alarms.o -> zb_zcl_alarms_req_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */

int zb_zcl_alarms_req_resp_handler(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *__src;
  undefined1 *puVar4;
  char *pcVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined1 *puVar8;
  undefined1 uVar9;
  char cVar10;
  char cVar11;
  undefined2 uVar12;
  uint uStack_40;
  undefined4 uStack_3c;
  undefined1 auStack_3b [3];
  undefined4 uStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  uint uStack_2c;
  
  iVar1 = zb_buf_get_tail_func(0x1b);
  if (((param_1 != 0) && (iVar1 != 0)) && (iVar2 = esp_zb_has_core_action_handler(), iVar2 != 0)) {
    if ((*(char *)(iVar1 + 0x14) == '\0') &&
       (iVar3 = esp_zb_zcl_get_cluster(*(undefined1 *)(iVar1 + 0xc),9,1), iVar3 != 0)) {
      if (*(char *)(iVar1 + 0x13) == '\x02') {
        memset(&stack0xffffffc4,0,0x1b);
        iVar1 = zb_buf_get_tail_func(param_1,0x1b);
        uVar9 = *(undefined1 *)(iVar1 + 0xc);
        __src = (void *)zb_buf_get_tail_func(param_1,0x1b);
        memcpy(&stack0xffffffc4,__src,0x1b);
        puVar4 = (undefined1 *)alarms_alarm_table_pop_earliest_entry(uVar9);
        if (puVar4 == (undefined1 *)0x0) {
          uVar6 = 0;
          uVar12 = 0;
          cVar11 = -0x75;
          uVar9 = 0;
        }
        else {
          uVar9 = *puVar4;
          uVar12 = *(undefined2 *)(puVar4 + 2);
          uVar6 = *(undefined4 *)(puVar4 + 4);
          cVar11 = '\0';
          free(puVar4);
        }
        zb_buf_reuse_func(param_1);
        puVar4 = (undefined1 *)zb_buf_reuse_func(param_1);
        *puVar4 = 0x19;
        pcVar5 = (char *)zb_zcl_get_ctx();
        cVar10 = *pcVar5;
        puVar8 = puVar4 + 4;
        *pcVar5 = cVar10 + '\x01';
        puVar4[1] = cVar10;
        puVar4[2] = 1;
        puVar4[3] = cVar11;
        if (cVar11 == '\0') {
          puVar4[4] = uVar9;
          zb_put_next_htole16(puVar4 + 5,uVar12);
          puVar8 = (undefined1 *)zb_put_next_htole32(uVar6);
        }
        zb_zcl_finish_and_send_packet
                  (param_1,puVar8,auStack_3b,2,uStack_34._3_1_,uStack_30 & 0xff,
                   uStack_2c >> 8 & 0xffff,9);
        return iVar2;
      }
      if (*(char *)(iVar1 + 0x13) == '\x03') {
        iVar1 = zb_buf_get_tail_func(param_1,0x1b);
        alarms_alarm_table_free(*(undefined1 *)(iVar1 + 0xc));
        uVar6 = zb_buf_get_tail_func(param_1,0x1b);
        uVar9 = 0;
_L0:
        zb_zcl_send_default_handler(param_1,uVar6,uVar9);
        return iVar2;
      }
    }
    else if ((*(char *)(iVar1 + 0x14) == '\x01') &&
            ((iVar3 = esp_zb_zcl_get_cluster(*(undefined1 *)(iVar1 + 0xc),9,2), iVar3 != 0 &&
             (*(char *)(iVar1 + 0x13) == '\x01')))) {
      uStack_40 = 0;
      uStack_3c = 0;
      uStack_38 = 0;
      uStack_34 = 0;
      uStack_30 = 0;
      iVar1 = zb_buf_get_tail_func(param_1,0x1b);
      uStack_38 = CONCAT31(uStack_38._1_3_,*(undefined1 *)(iVar1 + 0xc));
      uStack_38 = CONCAT22(9,(undefined2)uStack_38);
      iVar1 = zb_buf_len_func(param_1);
      uVar9 = 0x80;
      if (iVar1 != 0) {
        pcVar5 = (char *)zb_buf_begin_func(param_1);
        cVar11 = *pcVar5;
        uVar7 = zb_buf_len_func(param_1);
        if (uVar7 < 8) {
          uVar7 = 0;
          uVar12 = 0;
          cVar10 = '\0';
        }
        else {
          cVar10 = pcVar5[1];
          uVar12 = *(undefined2 *)(pcVar5 + 2);
          memcpy(&uStack_40,pcVar5 + 4,4);
          uVar7 = uStack_40;
        }
        uStack_34 = CONCAT31(uStack_34._1_3_,cVar11);
        if (cVar11 == '\0') {
          uStack_34 = (uint)CONCAT21(uVar12,cVar10) << 8;
          uStack_30 = uVar7;
        }
        iVar1 = esp_zb_core_action_handler_schedule(0x53,&stack0xffffffc4);
        uVar9 = iVar1 != 0;
      }
      uVar6 = zb_buf_get_tail_func(param_1,0x1b);
      goto _L0;
    }
  }
  return 0;
}

