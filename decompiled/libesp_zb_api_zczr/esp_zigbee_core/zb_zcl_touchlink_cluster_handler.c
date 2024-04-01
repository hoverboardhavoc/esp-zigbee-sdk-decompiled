/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zcl_touchlink_cluster_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */

undefined4 zb_zcl_touchlink_cluster_handler(undefined4 param_1)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  short sVar4;
  undefined4 *puVar5;
  undefined1 uVar6;
  undefined1 *puVar7;
  int iVar8;
  undefined2 *__dest;
  undefined4 uVar9;
  undefined2 *puVar10;
  undefined2 *puVar11;
  int iVar12;
  void *pvVar13;
  int iVar14;
  byte *pbVar15;
  undefined1 *puVar16;
  undefined *puVar17;
  undefined1 *puVar18;
  char cVar19;
  undefined2 *puVar20;
  uint uVar21;
  uint uVar22;
  undefined1 uVar23;
  uint uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  byte bStack_81;
  undefined1 uStack_80;
  undefined1 uStack_77;
  undefined4 local_70;
  short sStack_68;
  char cStack_66;
  byte bStack_65;
  uint uStack_64;
  undefined1 uStack_5b;
  undefined2 uStack_50;
  char cStack_4e;
  undefined2 *puStack_4c;
  
  iVar8 = zb_buf_get_tail_func(0x1b);
  if (iVar8 == 0) {
    return 0;
  }
  cVar19 = *(char *)(iVar8 + 0x14);
  if (cVar19 == '\x01') {
    cVar1 = *(char *)(iVar8 + 0x13);
    if (cVar1 == 'A') {
      __dest = (undefined2 *)malloc(3);
      zb_buf_get_tail_func(param_1,0x1b);
      iVar12 = zb_buf_len_func(param_1);
      if (iVar12 != 3) {
        uVar9 = esp_log_timestamp();
        puVar17 = &_L0;
_L0:
        esp_log_write(1,"ESP_ZIGBEE_CORE",puVar17,uVar9,"ESP_ZIGBEE_CORE");
        free(__dest);
        goto _L0;
      }
      pvVar13 = (void *)zb_buf_begin_func(param_1);
      memcpy(__dest,pvVar13,3);
      zb_buf_cut_left_func(param_1,3);
      iVar12 = zb_zcl_basic_message_create(param_1,&local_70);
      if (iVar12 != 0) goto _L0;
      cStack_4e = *(char *)(__dest + 1);
      uStack_50 = *__dest;
      local_70 = 0;
      puStack_4c = (undefined2 *)0x0;
      puVar10 = (undefined2 *)0x0;
      for (cVar19 = cStack_4e; cVar19 != '\0'; cVar19 = cVar19 + -1) {
        iVar12 = zb_buf_len_func(param_1);
        if (iVar12 == 3) {
          puVar20 = (undefined2 *)zb_buf_begin_func(param_1);
          uStack_8c._0_2_ = *puVar20;
          uStack_8c._2_1_ = *(undefined1 *)(puVar20 + 1);
          zb_buf_cut_left_func(param_1,3);
        }
        puVar11 = (undefined2 *)malloc(8);
        *(undefined4 *)(puVar11 + 2) = 0;
        *puVar11 = (undefined2)uStack_8c;
        *(char *)(puVar11 + 1) = (char)(undefined2)uStack_8c;
        puVar20 = puVar11;
        if (puVar10 != (undefined2 *)0x0) {
          *(undefined2 **)(puVar10 + 2) = puVar11;
          puVar20 = puStack_4c;
        }
        puStack_4c = puVar20;
        puVar10 = puVar11;
      }
      iVar12 = 0;
      puVar10 = puStack_4c;
      if (zb_core_action_cb != (code *)0x0) {
        iVar12 = (*zb_core_action_cb)(0x1060,&local_70);
        puVar10 = puStack_4c;
      }
      while (puVar10 != (undefined2 *)0x0) {
        puVar20 = *(undefined2 **)(puVar10 + 2);
        free(puVar10);
        puVar10 = puVar20;
      }
    }
    else {
      if (cVar1 != 'B') {
        if (cVar1 != '@') {
          return 0;
        }
        zb_buf_get_tail_func(param_1,0x1b);
        iVar12 = zb_buf_len_func(param_1);
        if (iVar12 == 0x10) {
          pvVar13 = (void *)zb_buf_begin_func(param_1);
          memcpy(&local_70,pvVar13,8);
          iVar12 = 0;
          sVar4 = *(short *)((int)pvVar13 + 8);
          cVar19 = *(char *)((int)pvVar13 + 10);
          bStack_65 = *(byte *)((int)pvVar13 + 0xb);
          cVar1 = *(char *)((int)pvVar13 + 0xf);
          uStack_64 = *(uint *)((int)pvVar13 + 0xc);
          puVar7 = zb_touchlink_device_endpoint_information_record_list;
          sStack_68 = sVar4;
          cStack_66 = cVar19;
          do {
            if (puVar7[0x11] == '\0') {
              pvVar13 = memcpy(zb_touchlink_device_endpoint_information_record_list + iVar12 * 0x12,
                               &local_70,0x10);
              *(undefined1 *)((int)pvVar13 + 0x11) = 1;
              break;
            }
            iVar14 = memcmp(puVar7,&local_70,8);
            if ((((iVar14 == 0) && (*(short *)(puVar7 + 8) == sVar4)) && (puVar7[10] == cVar19)) &&
               ((((uint)*(ushort *)(puVar7 + 0xc) == ((uStack_64 & 0xff) << 8 | (uint)bStack_65) &&
                 ((uint)*(ushort *)(puVar7 + 0xe) == (uStack_64 >> 8 & 0xffff))) &&
                (puVar7[0x10] == cVar1)))) break;
            iVar12 = iVar12 + 1;
            puVar7 = puVar7 + 0x12;
          } while (iVar12 != 0x10);
        }
        cVar19 = '\0';
        goto _L0;
      }
      __dest = (undefined2 *)malloc(3);
      zb_buf_get_tail_func(param_1,0x1b);
      iVar12 = zb_buf_len_func(param_1);
      if (iVar12 != 3) {
        uVar9 = esp_log_timestamp();
        puVar17 = &_LC4;
        goto _L0;
      }
      pvVar13 = (void *)zb_buf_begin_func(param_1);
      memcpy(__dest,pvVar13,3);
      zb_buf_cut_left_func(param_1,3);
      iVar12 = zb_zcl_basic_message_create(param_1,&local_70);
      if (iVar12 != 0) goto _L0;
      cStack_4e = *(char *)(__dest + 1);
      uStack_50 = *__dest;
      local_70 = 0;
      puStack_4c = (undefined2 *)0x0;
      puVar10 = (undefined2 *)0x0;
      for (cVar19 = cStack_4e; cVar19 != '\0'; cVar19 = cVar19 + -1) {
        iVar12 = zb_buf_len_func(param_1);
        if (iVar12 == 8) {
          puVar20 = (undefined2 *)zb_buf_begin_func(param_1);
          uStack_8c._0_2_ = *puVar20;
          uStack_8c._2_1_ = *(undefined1 *)(puVar20 + 1);
          uStack_8c._3_1_ = *(byte *)((int)puVar20 + 3);
          uStack_88 = *(uint *)(puVar20 + 2);
          zb_buf_cut_left_func(param_1,8);
        }
        puVar11 = (undefined2 *)malloc(0x10);
        *puVar11 = (undefined2)uStack_8c;
        *(undefined1 *)(puVar11 + 1) = uStack_8c._2_1_;
        *(undefined4 *)(puVar11 + 6) = 0;
        puVar11[2] = (ushort)((uStack_88 & 0xff) << 8) | (ushort)uStack_8c._3_1_;
        puVar11[3] = (short)(uStack_88 >> 8);
        *(undefined1 *)(puVar11 + 4) = uStack_88._3_1_;
        puVar20 = puVar11;
        if (puVar10 != (undefined2 *)0x0) {
          *(undefined2 **)(puVar10 + 6) = puVar11;
          puVar20 = puStack_4c;
        }
        puStack_4c = puVar20;
        puVar10 = puVar11;
      }
      iVar12 = 0;
      puVar10 = puStack_4c;
      if (zb_core_action_cb != (code *)0x0) {
        iVar12 = (*zb_core_action_cb)(0x1061,&local_70);
        puVar10 = puStack_4c;
      }
      while (puVar10 != (undefined2 *)0x0) {
        puVar20 = *(undefined2 **)(puVar10 + 6);
        free(puVar10);
        puVar10 = puVar20;
      }
    }
    free(__dest);
    cVar19 = iVar12 != 0;
    goto _L0;
  }
  if (cVar19 != '\0') {
    return 0;
  }
  if (*(char *)(iVar8 + 0x13) == 'A') {
    uVar9 = zb_buf_get_out_func(0);
    uStack_90 = 0;
    pvVar13 = (void *)zb_buf_get_tail_func(param_1,0x1b);
    memcpy(&uStack_8c,pvVar13,0x1b);
    iVar12 = zb_buf_len_func(param_1);
    if (iVar12 == 1) {
      puVar7 = (undefined1 *)zb_buf_begin_func(param_1);
      uVar23 = *puVar7;
      zb_apsme_get_groups_by_ep(0x20,&local_70,&uStack_90,uStack_80);
      uVar6 = g_zb;
      puVar7 = (undefined1 *)zb_buf_reuse_func(uVar9);
      *puVar7 = 0x19;
      puVar7[2] = 0x41;
      puVar7[3] = uVar6;
      puVar7[1] = uStack_77;
      puVar7[4] = uVar23;
      puVar7[5] = (char)uStack_90;
      puVar7 = puVar7 + 6;
      for (uVar22 = 0; uVar22 < uStack_90; uVar22 = uVar22 + 1 & 0xff) {
        *puVar7 = *(undefined1 *)((int)&local_70 + uVar22 * 2);
        uVar23 = *(undefined1 *)((int)&local_70 + uVar22 * 2 + 1);
        puVar7[2] = 0;
        puVar7[1] = uVar23;
        puVar7 = puVar7 + 3;
      }
      puVar5 = &uStack_8c;
      goto _L0;
    }
    uVar9 = esp_log_timestamp();
    puVar17 = &_LC5;
  }
  else {
    if (*(char *)(iVar8 + 0x13) != 'B') {
      return 0;
    }
    uVar9 = zb_buf_get_out_func();
    pvVar13 = (void *)zb_buf_get_tail_func(param_1,0x1b);
    memcpy(&local_70,pvVar13,0x1b);
    iVar12 = zb_buf_len_func(param_1);
    if (iVar12 == 1) {
      pbVar15 = (byte *)zb_buf_begin_func(param_1);
      bVar2 = *pbVar15;
      uVar22 = (uint)bVar2;
      iVar12 = zb_zcl_get_ctx();
      uVar23 = 0;
      if (*(int *)(iVar12 + 4) != 0) {
        iVar12 = zb_zcl_get_ctx();
        uVar23 = **(undefined1 **)(iVar12 + 4);
      }
      uVar21 = 0;
      puVar7 = zb_touchlink_device_endpoint_information_record_list + uVar22 * 0x12;
      for (; uVar22 < 0x10; uVar22 = uVar22 + 1 & 0xff) {
        if (puVar7[0x11] != '\0') {
          uVar21 = uVar21 + 1 & 0xff;
        }
        puVar7 = puVar7 + 0x12;
      }
      puVar16 = (undefined1 *)zb_buf_reuse_func(uVar9);
      *puVar16 = 0x19;
      puVar16[3] = uVar23;
      puVar16[1] = uStack_5b;
      puVar16[2] = 0x42;
      puVar16[4] = bVar2;
      puVar16[5] = (char)uVar21;
      puVar7 = puVar16 + 6;
      puVar18 = zb_touchlink_device_endpoint_information_record_list;
      for (uVar22 = 0; uVar21 != uVar22; uVar22 = uVar22 + 1 & 0xff) {
        uVar3 = *(undefined2 *)(puVar18 + 8);
        *puVar7 = (char)uVar3;
        uStack_8c._1_1_ = (undefined1)((ushort)uVar3 >> 8);
        puVar7[1] = uStack_8c._1_1_;
        puVar7[2] = puVar18[10];
        uVar3 = *(undefined2 *)(puVar18 + 0xc);
        puVar7[3] = (char)uVar3;
        uStack_8c._1_1_ = (undefined1)((ushort)uVar3 >> 8);
        puVar7[4] = uStack_8c._1_1_;
        uVar3 = *(undefined2 *)(puVar18 + 0xe);
        puVar7[5] = (char)uVar3;
        uStack_8c._1_1_ = (undefined1)((ushort)uVar3 >> 8);
        puVar7[6] = uStack_8c._1_1_;
        puVar7[7] = puVar18[0x10];
        puVar7 = puVar7 + 8;
        puVar18 = puVar18 + 0x12;
        uStack_8c._0_2_ = uVar3;
      }
      uStack_80 = 0;
      puVar5 = &local_70;
      puVar7 = puVar16 + 6 + uVar21 * 8;
      bStack_81 = bStack_65;
_L0:
      zb_zcl_finish_and_send_packet
                (uVar9,puVar7,(int)puVar5 + 1,2,bStack_81,uStack_80,0xc05e,0x1000);
      goto _L0;
    }
    uVar9 = esp_log_timestamp();
    puVar17 = &_LC6;
  }
  esp_log_write(1,"ESP_ZIGBEE_CORE",puVar17,uVar9,"ESP_ZIGBEE_CORE");
  cVar19 = '\x01';
_L0:
  zb_zcl_send_default_handler(param_1,iVar8,cVar19);
  return 1;
}

