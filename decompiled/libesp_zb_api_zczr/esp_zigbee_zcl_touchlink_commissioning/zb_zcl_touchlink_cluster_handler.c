/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_touchlink_commissioning.o -> zb_zcl_touchlink_cluster_handler
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
  char cVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined2 *__dest;
  undefined4 uVar10;
  undefined2 *puVar11;
  undefined2 *puVar12;
  int iVar13;
  void *pvVar14;
  int iVar15;
  byte *pbVar16;
  undefined1 *puVar17;
  undefined *puVar18;
  undefined1 *puVar19;
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
  
  iVar9 = zb_buf_get_tail_func(0x1b);
  if (iVar9 == 0) {
    return 0;
  }
  cVar7 = *(char *)(iVar9 + 0x14);
  if (cVar7 == '\x01') {
    cVar1 = *(char *)(iVar9 + 0x13);
    if (cVar1 == 'A') {
      __dest = (undefined2 *)malloc(3);
      zb_buf_get_tail_func(param_1,0x1b);
      iVar13 = zb_buf_len_func(param_1);
      if (iVar13 == 3) {
        pvVar14 = (void *)zb_buf_begin_func(param_1);
        memcpy(__dest,pvVar14,3);
        zb_buf_cut_left_func(param_1,3);
        iVar13 = zb_zcl_basic_message_create(param_1,&local_70);
        if (iVar13 != 0) goto _L0;
        cStack_4e = *(char *)(__dest + 1);
        uStack_50 = *__dest;
        local_70 = 0;
        puStack_4c = (undefined2 *)0x0;
        puVar11 = (undefined2 *)0x0;
        for (cVar7 = cStack_4e; cVar7 != '\0'; cVar7 = cVar7 + -1) {
          iVar13 = zb_buf_len_func(param_1);
          if (iVar13 == 3) {
            puVar20 = (undefined2 *)zb_buf_begin_func(param_1);
            uStack_8c._0_2_ = *puVar20;
            uStack_8c._2_1_ = *(undefined1 *)(puVar20 + 1);
            zb_buf_cut_left_func(param_1,3);
          }
          puVar12 = (undefined2 *)malloc(8);
          *(undefined4 *)(puVar12 + 2) = 0;
          *puVar12 = (undefined2)uStack_8c;
          *(char *)(puVar12 + 1) = (char)(undefined2)uStack_8c;
          puVar20 = puVar12;
          if (puVar11 != (undefined2 *)0x0) {
            *(undefined2 **)(puVar11 + 2) = puVar12;
            puVar20 = puStack_4c;
          }
          puStack_4c = puVar20;
          puVar11 = puVar12;
        }
        iVar13 = esp_zb_core_action_handler_schedule(0x1060,&local_70);
        puVar11 = puStack_4c;
        while (puVar11 != (undefined2 *)0x0) {
          puVar20 = *(undefined2 **)(puVar11 + 2);
          free(puVar11);
          puVar11 = puVar20;
        }
      }
      else {
        uVar10 = esp_log_timestamp();
        puVar18 = &_LC1;
_L0:
        esp_log_write(1,0x10000,puVar18,uVar10,0x10000);
        iVar13 = -1;
      }
    }
    else {
      if (cVar1 != 'B') {
        if (cVar1 != '@') {
          return 0;
        }
        zb_buf_get_tail_func(param_1,0x1b);
        iVar13 = zb_buf_len_func(param_1);
        if (iVar13 == 0x10) {
          pvVar14 = (void *)zb_buf_begin_func(param_1);
          memcpy(&local_70,pvVar14,8);
          iVar13 = 0;
          sVar4 = *(short *)((int)pvVar14 + 8);
          cVar7 = *(char *)((int)pvVar14 + 10);
          bStack_65 = *(byte *)((int)pvVar14 + 0xb);
          cVar1 = *(char *)((int)pvVar14 + 0xf);
          uStack_64 = *(uint *)((int)pvVar14 + 0xc);
          puVar8 = zb_touchlink_device_endpoint_information_record_list;
          sStack_68 = sVar4;
          cStack_66 = cVar7;
          do {
            if (puVar8[0x11] == '\0') {
              pvVar14 = memcpy(zb_touchlink_device_endpoint_information_record_list + iVar13 * 0x12,
                               &local_70,0x10);
              *(undefined1 *)((int)pvVar14 + 0x11) = 1;
              break;
            }
            iVar15 = memcmp(puVar8,&local_70,8);
            if ((((iVar15 == 0) && (*(short *)(puVar8 + 8) == sVar4)) && (puVar8[10] == cVar7)) &&
               ((((uint)*(ushort *)(puVar8 + 0xc) == ((uStack_64 & 0xff) << 8 | (uint)bStack_65) &&
                 ((uint)*(ushort *)(puVar8 + 0xe) == (uStack_64 >> 8 & 0xffff))) &&
                (puVar8[0x10] == cVar1)))) break;
            iVar13 = iVar13 + 1;
            puVar8 = puVar8 + 0x12;
          } while (iVar13 != 0x10);
        }
        cVar7 = '\0';
        goto _L0;
      }
      __dest = (undefined2 *)malloc(3);
      zb_buf_get_tail_func(param_1,0x1b);
      iVar13 = zb_buf_len_func(param_1);
      if (iVar13 != 3) {
        uVar10 = esp_log_timestamp();
        puVar18 = &_LC2;
        goto _L0;
      }
      pvVar14 = (void *)zb_buf_begin_func(param_1);
      memcpy(__dest,pvVar14,3);
      zb_buf_cut_left_func(param_1,3);
      iVar13 = zb_zcl_basic_message_create(param_1,&local_70);
      if (iVar13 != 0) goto _L0;
      cStack_4e = *(char *)(__dest + 1);
      uStack_50 = *__dest;
      local_70 = 0;
      puStack_4c = (undefined2 *)0x0;
      puVar11 = (undefined2 *)0x0;
      for (cVar7 = cStack_4e; cVar7 != '\0'; cVar7 = cVar7 + -1) {
        iVar13 = zb_buf_len_func(param_1);
        if (iVar13 == 8) {
          puVar20 = (undefined2 *)zb_buf_begin_func(param_1);
          uStack_8c._0_2_ = *puVar20;
          uStack_8c._2_1_ = *(undefined1 *)(puVar20 + 1);
          uStack_8c._3_1_ = *(byte *)((int)puVar20 + 3);
          uStack_88 = *(uint *)(puVar20 + 2);
          zb_buf_cut_left_func(param_1,8);
        }
        puVar12 = (undefined2 *)malloc(0x10);
        *puVar12 = (undefined2)uStack_8c;
        *(undefined1 *)(puVar12 + 1) = uStack_8c._2_1_;
        *(undefined4 *)(puVar12 + 6) = 0;
        puVar12[2] = (ushort)((uStack_88 & 0xff) << 8) | (ushort)uStack_8c._3_1_;
        puVar12[3] = (short)(uStack_88 >> 8);
        *(undefined1 *)(puVar12 + 4) = uStack_88._3_1_;
        puVar20 = puVar12;
        if (puVar11 != (undefined2 *)0x0) {
          *(undefined2 **)(puVar11 + 6) = puVar12;
          puVar20 = puStack_4c;
        }
        puStack_4c = puVar20;
        puVar11 = puVar12;
      }
      iVar13 = esp_zb_core_action_handler_schedule(0x1061,&local_70);
      puVar11 = puStack_4c;
      while (puVar11 != (undefined2 *)0x0) {
        puVar20 = *(undefined2 **)(puVar11 + 6);
        free(puVar11);
        puVar11 = puVar20;
      }
    }
    free(__dest);
    cVar7 = iVar13 != 0;
    goto _L0;
  }
  if (cVar7 != '\0') {
    return 0;
  }
  if (*(char *)(iVar9 + 0x13) == 'A') {
    uVar10 = zb_buf_get_out_func(0);
    uStack_90 = 0;
    pvVar14 = (void *)zb_buf_get_tail_func(param_1,0x1b);
    memcpy(&uStack_8c,pvVar14,0x1b);
    iVar13 = zb_buf_len_func(param_1);
    if (iVar13 == 1) {
      puVar8 = (undefined1 *)zb_buf_begin_func(param_1);
      uVar23 = *puVar8;
      zb_apsme_get_groups_by_ep(0x20,&local_70,&uStack_90,uStack_80);
      uVar6 = g_zb;
      puVar8 = (undefined1 *)zb_buf_reuse_func(uVar10);
      *puVar8 = 0x19;
      puVar8[2] = 0x41;
      puVar8[3] = uVar6;
      puVar8[1] = uStack_77;
      puVar8[4] = uVar23;
      puVar8[5] = (char)uStack_90;
      puVar8 = puVar8 + 6;
      for (uVar22 = 0; uVar22 < uStack_90; uVar22 = uVar22 + 1 & 0xff) {
        *puVar8 = *(undefined1 *)((int)&local_70 + uVar22 * 2);
        uVar23 = *(undefined1 *)((int)&local_70 + uVar22 * 2 + 1);
        puVar8[2] = 0;
        puVar8[1] = uVar23;
        puVar8 = puVar8 + 3;
      }
      puVar5 = &uStack_8c;
      goto _L0;
    }
    uVar10 = esp_log_timestamp();
    puVar18 = &_LC3;
  }
  else {
    if (*(char *)(iVar9 + 0x13) != 'B') {
      return 0;
    }
    uVar10 = zb_buf_get_out_func();
    pvVar14 = (void *)zb_buf_get_tail_func(param_1,0x1b);
    memcpy(&local_70,pvVar14,0x1b);
    iVar13 = zb_buf_len_func(param_1);
    if (iVar13 == 1) {
      pbVar16 = (byte *)zb_buf_begin_func(param_1);
      bVar2 = *pbVar16;
      uVar22 = (uint)bVar2;
      iVar13 = zb_zcl_get_ctx();
      uVar23 = 0;
      if (*(int *)(iVar13 + 4) != 0) {
        iVar13 = zb_zcl_get_ctx();
        uVar23 = **(undefined1 **)(iVar13 + 4);
      }
      uVar21 = 0;
      puVar8 = zb_touchlink_device_endpoint_information_record_list + uVar22 * 0x12;
      for (; uVar22 < 0x10; uVar22 = uVar22 + 1 & 0xff) {
        if (puVar8[0x11] != '\0') {
          uVar21 = uVar21 + 1 & 0xff;
        }
        puVar8 = puVar8 + 0x12;
      }
      puVar17 = (undefined1 *)zb_buf_reuse_func(uVar10);
      *puVar17 = 0x19;
      puVar17[3] = uVar23;
      puVar17[1] = uStack_5b;
      puVar17[2] = 0x42;
      puVar17[4] = bVar2;
      puVar17[5] = (char)uVar21;
      puVar8 = puVar17 + 6;
      puVar19 = zb_touchlink_device_endpoint_information_record_list;
      for (uVar22 = 0; uVar21 != uVar22; uVar22 = uVar22 + 1 & 0xff) {
        uVar3 = *(undefined2 *)(puVar19 + 8);
        *puVar8 = (char)uVar3;
        uStack_8c._1_1_ = (undefined1)((ushort)uVar3 >> 8);
        puVar8[1] = uStack_8c._1_1_;
        puVar8[2] = puVar19[10];
        uVar3 = *(undefined2 *)(puVar19 + 0xc);
        puVar8[3] = (char)uVar3;
        uStack_8c._1_1_ = (undefined1)((ushort)uVar3 >> 8);
        puVar8[4] = uStack_8c._1_1_;
        uVar3 = *(undefined2 *)(puVar19 + 0xe);
        puVar8[5] = (char)uVar3;
        uStack_8c._1_1_ = (undefined1)((ushort)uVar3 >> 8);
        puVar8[6] = uStack_8c._1_1_;
        puVar8[7] = puVar19[0x10];
        puVar8 = puVar8 + 8;
        puVar19 = puVar19 + 0x12;
        uStack_8c._0_2_ = uVar3;
      }
      uStack_80 = 0;
      puVar5 = &local_70;
      puVar8 = puVar17 + 6 + uVar21 * 8;
      bStack_81 = bStack_65;
_L0:
      zb_zcl_finish_and_send_packet
                (uVar10,puVar8,(int)puVar5 + 1,2,bStack_81,uStack_80,0xc05e,0x1000);
      goto _L0;
    }
    uVar10 = esp_log_timestamp();
    puVar18 = &_LC4;
  }
  esp_log_write(1,0x10000,puVar18,uVar10,0x10000);
  cVar7 = '\x01';
_L0:
  zb_zcl_send_default_handler(param_1,iVar9,cVar7);
  return 1;
}

