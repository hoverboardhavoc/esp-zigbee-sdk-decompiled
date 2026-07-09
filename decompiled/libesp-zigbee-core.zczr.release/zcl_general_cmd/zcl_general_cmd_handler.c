/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_general_cmd.o -> zcl_general_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_general_cmd_handler(uint param_1)

{
  undefined2 uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  short *psVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  void *pvVar10;
  size_t sVar11;
  int iVar12;
  char *pcVar13;
  undefined1 *puVar14;
  undefined2 *puVar15;
  undefined2 *puVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 *puVar19;
  byte bVar20;
  byte bVar21;
  void *pvVar22;
  ushort *puVar23;
  undefined2 uVar24;
  undefined2 auStack_11c [2];
  undefined2 uStack_118;
  ushort local_114;
  ushort uStack_112;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 local_108;
  void *pvStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  uint uStack_f8;
  void *pvStack_f4;
  uint uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  uint uStack_e4;
  char *pcStack_e0;
  uint uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  uint uStack_d0;
  char *pcStack_cc;
  uint uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  uint uStack_bc;
  char *pcStack_b8;
  uint uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  uint uStack_a8;
  undefined2 *puStack_a4;
  uint uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  uint uStack_94;
  undefined4 uStack_90;
  uint uStack_8c;
  ushort local_88 [4];
  uint uStack_80;
  undefined1 auStack_7c [4];
  void *pvStack_78;
  byte bStack_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  uint uStack_68;
  undefined4 uStack_64;
  void *pvStack_60;
  byte bStack_5c;
  undefined1 auStack_58 [36];
  int iStack_34;
  
  memset(auStack_58,0,0x28);
  if (param_1 != 0) goto _L0;
_L166:
  while( true ) {
    __assert_func(0,0,0,0);
_L0:
    iVar4 = zcl_packet_init(auStack_58,*(ushort *)(param_1 + 0x1a) >> 2 & 1);
    if (iVar4 != 0) goto _L0;
    bVar21 = *(byte *)(param_1 + 0x20);
    if (bVar21 == 9) goto _L0;
    if (9 < bVar21) break;
    if (bVar21 == 4) {
      uStack_ec = 0;
      uStack_e8 = 0;
      uStack_e4 = 0;
      pcStack_e0 = (char *)0x0;
      uStack_dc = 0;
      if ((*(int *)(param_1 + 0x24) != 0) && (iStack_34 != 0)) {
        iVar4 = zcl_packet_to_message(&uStack_ec,param_1);
        if (iVar4 != 0) goto _L208;
        local_70 = local_70 & 0xffff0000;
        uStack_e4 = param_1;
        uVar5 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
        goto _L0;
      }
    }
    else if (bVar21 < 5) {
      if (bVar21 == 1) {
        uStack_100 = 0;
        uStack_fc = 0;
        uStack_f8 = 0;
        pvStack_f4 = (void *)0x0;
        uStack_f0 = 0;
        if ((*(int *)(param_1 + 0x24) != 0) && (iStack_34 != 0)) {
          iVar4 = zcl_packet_to_message(&uStack_100,param_1);
          if (iVar4 != 0) goto _L0;
          uVar18 = *(undefined4 *)(param_1 + 0x24);
          local_70 = local_70 & 0xffff0000;
          uStack_f8 = param_1;
          uVar5 = zmsg_get_length(uVar18);
          goto _L0;
        }
      }
      else if (bVar21 == 2) {
        iVar4 = *(int *)(param_1 + 0x24);
        local_108 = 0;
        pvStack_104 = (void *)0x0;
        if ((iVar4 != 0) && (iStack_34 != 0)) {
          uVar24 = 0;
          if ((*(byte *)(param_1 + 0x1a) & 4) != 0) {
            uVar24 = *(undefined2 *)(param_1 + 0x1c);
          }
          iVar9 = af_get_ep_desc(*(undefined1 *)(param_1 + 0x15));
          if (iVar9 == 0) goto _L0;
          uVar18 = 1;
          if ((*(byte *)(param_1 + 0x1a) & 8) != 0) {
            uVar18 = 2;
          }
          iVar9 = af_endpoint_get_cluster_desc(*(undefined2 *)(param_1 + 0x16),uVar18);
          if (iVar9 == 0) goto _L0;
          uVar7 = zmsg_get_length(iVar4);
          local_70 = local_70 & 0xffff0000;
          while ((local_70 & 0xffff) < uVar7) {
            local_108 = 0;
            pvStack_104 = (void *)0x0;
            af_read_le16_isra_0(iVar4,&local_70,&local_108);
            af_read_le8_isra_0(iVar4,&local_70,(int)&local_108 + 2);
            iVar3 = 0x86;
            sVar11 = zcl_packet_read_variable_attr_size
                               (*(undefined4 *)(param_1 + 0x24),local_70 & 0xffff,
                                local_108 >> 0x10 & 0xff);
            pvStack_104 = calloc(1,sVar11);
            zcl_packet_read_variable_attr_value
                      (iVar4,&local_70,local_108 >> 0x10 & 0xff,pvStack_104);
            iVar12 = zcl_cluster_get_attr_desc(iVar9,local_108 & 0xffff,uVar24);
            if (iVar12 != 0) {
              iVar3 = 0x8d;
              if (local_108._2_1_ == *(char *)(iVar12 + 2)) {
                bVar21 = *(byte *)(iVar12 + 3);
                iVar3 = 0x88;
                if (((bVar21 != 1) && ((bVar21 & 2) != 0)) && (iVar3 = 0x86, (bVar21 & 0x40) == 0))
                {
                  uVar18 = 1;
                  if ((*(byte *)(param_1 + 0x1a) & 8) != 0) {
                    uVar18 = 2;
                  }
                  iVar3 = zcl_set_attr_value(*(undefined1 *)(param_1 + 0x15),
                                             *(undefined2 *)(param_1 + 0x16),uVar18,
                                             local_108 & 0xffff,uVar24,pvStack_104,0);
                  if (iVar3 == 0) {
                    if ((*(short *)(param_1 + 0x16) == 0x500) &&
                       ((*(byte *)(param_1 + 0x1a) & 8) == 0)) {
                      ias_zone_cluster_srv_set_attr_val_post_proc
                                (param_1,local_108 & 0xffff,pvStack_104);
                    }
                    uVar18 = 1;
                    if ((*(byte *)(param_1 + 0x1a) & 8) != 0) {
                      uVar18 = 2;
                    }
                    zcl_message_notify_attr_value
                              (*(undefined1 *)(param_1 + 0x15),*(undefined2 *)(param_1 + 0x16),
                               uVar18,iVar12);
                  }
                }
              }
            }
            zmsg_append_u8(iStack_34,iVar3);
            if (iVar3 != 0) {
              zmsg_append_le16(iStack_34,local_108 & 0xffff);
            }
            mm_free(pvStack_104);
          }
          uVar5 = 0x80;
          if (uVar7 != (local_70 & 0xffff)) goto _L0;
          uVar18 = 4;
          goto _L0;
        }
      }
      else {
        if (bVar21 != 0) {
_L510:
          iVar4 = 0x81;
          goto _L0;
        }
        iVar4 = *(int *)(param_1 + 0x24);
        auStack_11c[0] = 0;
        if ((iVar4 != 0) && (iStack_34 != 0)) {
          uVar24 = 0;
          if ((*(byte *)(param_1 + 0x1a) & 4) != 0) {
            uVar24 = *(undefined2 *)(param_1 + 0x1c);
          }
          uVar5 = zmsg_get_length(iVar4);
          local_88[0] = 0;
          if ((uVar5 & 1) != 0) goto _L0;
          goto _L0;
        }
      }
    }
    else if (bVar21 == 7) {
      uStack_d8 = 0;
      uStack_d4 = 0;
      uStack_d0 = 0;
      pcStack_cc = (char *)0x0;
      uStack_c8 = 0;
      if ((*(int *)(param_1 + 0x24) != 0) && (iStack_34 != 0)) {
        iVar4 = zcl_packet_to_message(&uStack_d8,param_1);
        if (iVar4 != 0) goto _L241;
        local_70 = local_70 & 0xffff0000;
        uStack_d0 = param_1;
        uVar5 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
        goto _L0;
      }
    }
    else {
      if (bVar21 != 8) {
        if (bVar21 != 6) goto _L510;
        local_70 = 0;
        uStack_6c = 0;
        uStack_68 = 0;
        uStack_64 = (void *)0x0;
        uVar18 = *(undefined4 *)(param_1 + 0x24);
        uVar24 = 0;
        if ((*(byte *)(param_1 + 0x1a) & 4) != 0) {
          uVar24 = *(undefined2 *)(param_1 + 0x1c);
        }
        iVar4 = af_get_ep_desc(*(undefined1 *)(param_1 + 0x15));
        if (iVar4 == 0) {
          uVar5 = 0x81;
          goto _L0;
        }
        iVar4 = af_endpoint_get_cluster_desc
                          (*(undefined2 *)(param_1 + 0x16),
                           ((*(byte *)(param_1 + 0x1a) & 8) != 0) + '\x01');
        if (iVar4 == 0) {
          uVar5 = 0xc3;
          goto _L0;
        }
        uVar7 = zmsg_get_length(uVar18);
        local_88[0] = 0;
        goto _L0;
      }
      iVar4 = *(int *)(param_1 + 0x24);
      uStack_110 = 0;
      if ((iVar4 != 0) && (iStack_34 != 0)) {
        uVar24 = 0;
        if ((*(byte *)(param_1 + 0x1a) & 4) != 0) {
          uVar24 = *(undefined2 *)(param_1 + 0x1c);
        }
        puVar14 = (undefined1 *)af_get_ep_desc(*(undefined1 *)(param_1 + 0x15));
        if (puVar14 == (undefined1 *)0x0) {
_L0:
          uVar5 = 0x81;
          goto _L0;
        }
        puVar15 = (undefined2 *)
                  af_endpoint_get_cluster_desc
                            (*(undefined2 *)(param_1 + 0x16),
                             ((*(byte *)(param_1 + 0x1a) & 8) != 0) + '\x01');
        if (puVar15 == (undefined2 *)0x0) goto _L0;
        uVar5 = zmsg_get_length(iVar4);
        local_70 = local_70 & 0xffff0000;
        goto _L0;
      }
    }
  }
  if (bVar21 == 0xd) {
    memset(local_88,0,0x18);
    if ((*(int *)(param_1 + 0x24) != 0) && (iStack_34 != 0)) {
      iVar4 = zcl_packet_to_message(local_88,param_1);
      uVar5 = 0x80;
      if (iVar4 == 0) {
        local_70 = local_70 & 0xffff0000;
        uStack_80 = param_1;
        uVar5 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&local_70,auStack_7c);
        while ((local_70 & 0xffff) < uVar5) {
          pvVar22 = calloc(1,8);
          af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&local_70,pvVar22);
          af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&local_70,(int)pvVar22 + 2);
          *(void **)((int)pvVar22 + 4) = pvStack_78;
          pvStack_78 = pvVar22;
        }
        bStack_74 = 0xfe;
        zcl_core_action_schedule(6,local_88);
        uVar5 = (uint)bStack_74;
        if (uVar5 == 0xfe) {
          uVar5 = 0;
        }
      }
      while (pvStack_78 != (void *)0x0) {
        pvVar22 = *(void **)((int)pvStack_78 + 4);
        mm_free();
        pvStack_78 = pvVar22;
      }
      goto _L0;
    }
    goto _L166;
  }
  if (bVar21 < 0xe) {
    iVar4 = *(int *)(param_1 + 0x24);
    if (bVar21 == 0xb) {
      uStack_9c = 0;
      uStack_98 = 0;
      uStack_94 = 0;
      uStack_90 = 0;
      uStack_8c = 0;
      uStack_112 = 0;
      if ((iVar4 != 0) && (iStack_34 != 0)) {
        iVar4 = zcl_packet_to_message(&uStack_9c,param_1);
        uVar5 = 0xfe;
        if (iVar4 == 0) {
          uStack_94 = param_1;
          af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_112,&uStack_90);
          af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_112,(int)&uStack_90 + 1);
          uVar7 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
          uVar5 = 0x80;
          if (uStack_112 <= uVar7) {
            uStack_8c = CONCAT31(uStack_8c._1_3_,0xfe);
            zcl_core_action_schedule(8,&uStack_9c,0x80);
            uVar5 = uStack_8c & 0xff;
            if (uVar5 == 0xfe) {
              uVar5 = 0;
            }
          }
        }
        goto _L0;
      }
      goto _L166;
    }
    if (bVar21 != 0xc) {
      uStack_b0 = 0;
      uStack_ac = 0;
      uStack_a8 = 0;
      puStack_a4 = (undefined2 *)0x0;
      uStack_a0 = 0;
      local_114 = 0;
      if ((iVar4 != 0) && (iStack_34 != 0)) {
        uVar5 = zmsg_get_length(iVar4);
        puStack_a4 = (undefined2 *)0x0;
        iVar4 = zcl_packet_to_message(&uStack_b0,param_1);
        if (iVar4 != 0) goto _L0;
        uVar24 = 0;
        uStack_a8 = param_1;
        if ((*(byte *)(param_1 + 0x1a) & 4) != 0) {
          uVar24 = *(undefined2 *)(param_1 + 0x1c);
        }
        goto _L0;
      }
      goto _L166;
    }
    uStack_10c = 0;
    if ((iVar4 == 0) || (iStack_34 == 0)) goto _L166;
    iVar9 = af_get_ep_desc(*(undefined1 *)(param_1 + 0x15));
    if (iVar9 == 0) goto _L0;
    iVar9 = af_endpoint_get_cluster_desc
                      (*(undefined2 *)(param_1 + 0x16),
                       ((*(byte *)(param_1 + 0x1a) & 8) != 0) + '\x01');
    if (iVar9 != 0) {
      uVar7 = zmsg_get_length(iVar4);
      local_70 = local_70 & 0xffff0000;
      uVar5 = 0;
      goto _L0;
    }
  }
  else {
    if (bVar21 != 0x13) {
      if (bVar21 < 0x14) {
        if (bVar21 == 0x11) goto _L0;
        bVar20 = 0x12;
      }
      else {
        bVar20 = 0x14;
      }
      if (bVar21 != bVar20) goto _L510;
      memset(&local_70,0,0x18);
      if ((*(int *)(param_1 + 0x24) != 0) && (iStack_34 != 0)) {
        iVar4 = zcl_packet_to_message(&local_70,param_1);
        uVar5 = 0x80;
        if (iVar4 == 0) {
          local_88[0] = 0;
          uStack_68 = param_1;
          uVar5 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
          af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),local_88,(int)&uStack_64 + 1);
          uStack_64 = (void *)CONCAT31(uStack_64._1_3_,*(char *)(param_1 + 0x20) == '\x12');
          while (local_88[0] < uVar5) {
            pvVar22 = calloc(1,8);
            af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),local_88,pvVar22);
            *(void **)((int)pvVar22 + 4) = pvStack_60;
            pvStack_60 = pvVar22;
          }
          bStack_5c = 0xfe;
          zcl_core_action_schedule(7,&local_70);
          uVar5 = (uint)bStack_5c;
          if (uVar5 == 0xfe) {
            uVar5 = 0;
          }
        }
        while (pvStack_60 != (void *)0x0) {
          pvVar22 = *(void **)((int)pvStack_60 + 4);
          mm_free();
          pvStack_60 = pvVar22;
        }
        goto _L0;
      }
      goto _L166;
    }
_L0:
    iVar4 = *(int *)(param_1 + 0x24);
    uStack_118 = 0;
    if ((iVar4 == 0) || (iStack_34 == 0)) goto _L166;
    iVar9 = af_get_ep_desc(*(undefined1 *)(param_1 + 0x15));
    if (iVar9 == 0) goto _L0;
    puVar15 = (undefined2 *)
              af_endpoint_get_cluster_desc
                        (*(undefined2 *)(param_1 + 0x16),
                         ((*(byte *)(param_1 + 0x1a) & 8) != 0) + '\x01');
    if (puVar15 != (undefined2 *)0x0) {
      uVar7 = zmsg_get_length(iVar4);
      local_88[0] = 0;
      af_read_le8_isra_0(iVar4,local_88,&uStack_118);
      af_read_le8_isra_0(iVar4,local_88,(int)&uStack_118 + 1);
      uVar5 = 0x80;
      if (local_88[0] != uVar7) goto _L0;
      zmsg_append_u8(iStack_34,0,0x80);
      iVar4 = zcl_cluster_template_find(*puVar15,*(undefined1 *)(puVar15 + 1));
      if ((iVar4 != 0) && (*(code **)(iVar4 + 0xc) != (code *)0x0)) {
        local_70 = 0;
        uVar5 = (**(code **)(iVar4 + 0xc))(*(char *)(param_1 + 0x20) == '\x11',&local_70);
        uVar7 = 0;
        bVar21 = 0;
        while ((((uVar7 & 0xffff) < uVar5 && (local_70 != 0)) && (bVar21 < uStack_118._1_1_))) {
          if ((byte)uStack_118 <= *(byte *)(local_70 + uVar7)) {
            bVar21 = bVar21 + 1;
            zmsg_append_u8(iStack_34);
          }
          uVar7 = uVar7 + 1;
        }
        uStack_9c = CONCAT31(uStack_9c._1_3_,(uVar7 & 0xffff) == uVar5);
        zmsg_write_bytes(0,1,&uStack_9c);
        uVar18 = 0x14;
        if (*(char *)(param_1 + 0x20) == '\x11') {
          uVar18 = 0x12;
        }
        goto _L0;
      }
      goto _L0;
    }
  }
_L0:
  uVar5 = 0xc3;
  goto _L0;
_L0:
  uStack_c4 = 0;
  uStack_c0 = 0;
  uStack_bc = 0;
  pcStack_b8 = (char *)0x0;
  uStack_b4 = 0;
  if ((*(int *)(param_1 + 0x24) == 0) || (iStack_34 == 0)) goto _L166;
  iVar4 = zcl_packet_to_message(&uStack_c4,param_1);
  if (iVar4 == 0) {
    local_70 = local_70 & 0xffff0000;
    uStack_bc = param_1;
    uVar5 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    while ((local_70 & 0xffff) < uVar5) {
      pcVar13 = (char *)calloc(1,0x20);
      *(char **)(pcVar13 + 0x18) = pcStack_b8;
      pcStack_b8 = pcVar13;
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&local_70,pcVar13);
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&local_70,pcVar13 + 1);
      af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&local_70,pcVar13 + 2);
      if (uVar5 < (local_70 & 0xffff)) goto _L264;
      if (*pcVar13 == '\0') {
        if (pcVar13[1] == '\0') {
          af_read_le8_isra_0();
          af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&local_70,pcVar13 + 10);
          af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&local_70,pcVar13 + 0xc);
          iVar4 = zcl_attr_type_is_analog(pcVar13[8]);
          if (iVar4 == 0) {
            pcVar13[0x10] = '\0';
            pcVar13[0x11] = '\0';
            pcVar13[0x12] = '\0';
            pcVar13[0x13] = '\0';
            pcVar13[0x14] = '\0';
            pcVar13[0x15] = '\0';
            pcVar13[0x16] = '\0';
            pcVar13[0x17] = '\0';
          }
          else {
            zcl_packet_read_variable_attr_value
                      (*(undefined4 *)(param_1 + 0x24),&local_70,pcVar13[8],pcVar13 + 0x10);
          }
        }
        else {
          af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&local_70,pcVar13 + 8);
        }
      }
      else {
        memset(pcVar13 + 8,0xff,0x10);
      }
    }
    uStack_b4 = CONCAT31(uStack_b4._1_3_,0xfe);
    zcl_core_action_schedule(4,&uStack_c4);
    uVar5 = uStack_b4 & 0xff;
    if (uVar5 == 0xfe) {
      uVar5 = 0;
    }
  }
  else {
_L264:
    uVar5 = 0x80;
  }
  while (pcStack_b8 != (char *)0x0) {
    pcVar13 = *(char **)(pcStack_b8 + 0x18);
    mm_free(pcStack_b8);
    pcStack_b8 = pcVar13;
  }
  goto _L0;
_L0:
  puVar15 = puStack_a4;
  if (uVar5 <= local_114) goto _L0;
  puVar16 = (undefined2 *)calloc(1,0xc);
  *(undefined2 **)(puVar16 + 4) = puVar15;
  puStack_a4 = puVar16;
  af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&local_114,puVar16);
  af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&local_114,puVar16 + 1);
  if (uVar5 < local_114) goto _L0;
  sVar11 = zcl_packet_read_variable_attr_size
                     (*(undefined4 *)(param_1 + 0x24),*(undefined1 *)(puVar16 + 1));
  pvVar22 = calloc(1,sVar11);
  *(void **)(puVar16 + 2) = pvVar22;
  zcl_packet_read_variable_attr_value
            (*(undefined4 *)(param_1 + 0x24),&local_114,*(undefined1 *)(puVar16 + 1),pvVar22);
  goto _L0;
_L0:
  for (; puVar15 != (undefined2 *)0x0; puVar15 = *(undefined2 **)(puVar15 + 4)) {
    zcl_reporting_mark_recv_attr_report
              (*(undefined1 *)(param_1 + 0x15),*(undefined2 *)(param_1 + 0x16),
               ((*(byte *)(param_1 + 0x1a) & 8) != 0) + '\x01',*puVar15,uVar24);
  }
  uStack_a0 = CONCAT31(uStack_a0._1_3_,0xfe);
  zcl_core_action_schedule(5,&uStack_b0);
  uVar5 = uStack_a0 & 0xff;
  if (uVar5 == 0xfe) {
    uVar5 = 0;
  }
_L0:
  while (puStack_a4 != (undefined2 *)0x0) {
    puVar15 = *(undefined2 **)(puStack_a4 + 4);
    if (*(int *)(puStack_a4 + 2) != 0) {
      mm_free();
    }
    mm_free(puStack_a4);
    puStack_a4 = puVar15;
  }
  goto _L0;
_L0:
  uVar5 = 0x80;
  goto _L0;
_L0:
  if ((local_70 & 0xffff) < uVar7) {
    af_read_le16_isra_0(iVar4,&local_70,&uStack_10c);
    af_read_le8_isra_0(iVar4,&local_70,(int)&uStack_10c + 2);
    if ((local_70 & 0xffff) != uVar7) goto _L0;
    puVar23 = (ushort *)0x0;
    zmsg_append_u8(iStack_34,1);
    do {
      do {
        puVar23 = (ushort *)zcl_cluster_get_next_attr_desc(iVar9,puVar23);
        if (puVar23 == (ushort *)0x0) goto _L0;
      } while ((uint)*puVar23 < (uStack_10c & 0xffff));
      if (((*(byte *)((int)puVar23 + 3) & 0x40) == 0) && (*puVar23 != 0xfffd)) {
        uVar5 = uVar5 + 1 & 0xff;
        zmsg_append_le16(iStack_34);
        zmsg_append_u8(iStack_34,(char)puVar23[1]);
      }
    } while (uVar5 < (uStack_10c >> 0x10 & 0xff));
    local_88[0] = local_88[0] & 0xff00;
    zmsg_write_bytes(iStack_34,0,1,local_88);
    goto _L0;
  }
  uVar18 = 0xd;
  goto _L0;
_L0:
  if ((local_70 & 0xffff) < uVar5) {
    pcVar13 = (char *)calloc(1,8);
    *(char **)(pcVar13 + 4) = pcStack_e0;
    pcStack_e0 = pcVar13;
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&local_70,pcVar13);
    if (uVar5 < (local_70 & 0xffff)) goto _L208;
    if (*pcVar13 == '\0') {
      pcVar13[2] = -1;
      pcVar13[3] = -1;
    }
    else {
      af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&local_70,pcVar13 + 2);
    }
    goto _L0;
  }
  uStack_dc = CONCAT31(uStack_dc._1_3_,0xfe);
  zcl_core_action_schedule(2,&uStack_ec);
  uVar5 = uStack_dc & 0xff;
  if (uVar5 == 0xfe) {
    uVar5 = 0;
  }
_L0:
  while (pcStack_e0 != (char *)0x0) {
    pcVar13 = *(char **)(pcStack_e0 + 4);
    mm_free(pcStack_e0);
    pcStack_e0 = pcVar13;
  }
  goto _L0;
_L208:
  uVar5 = 0x80;
  goto _L0;
_L0:
  if ((local_70 & 0xffff) < uVar5) {
    pcVar13 = (char *)calloc(1,8);
    *(char **)(pcVar13 + 4) = pcStack_cc;
    pcStack_cc = pcVar13;
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&local_70,pcVar13);
    if (uVar5 < (local_70 & 0xffff)) goto _L241;
    if (*pcVar13 == '\0') {
      pcVar13[1] = -1;
      pcVar13[2] = -1;
      pcVar13[3] = -1;
    }
    else {
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&local_70,pcVar13 + 1);
      af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&local_70,pcVar13 + 2);
    }
    goto _L0;
  }
  uStack_c8 = CONCAT31(uStack_c8._1_3_,0xfe);
  zcl_core_action_schedule(3,&uStack_d8);
  uVar5 = uStack_c8 & 0xff;
  if (uVar5 == 0xfe) {
    uVar5 = 0;
  }
_L0:
  while (pcStack_cc != (char *)0x0) {
    pcVar13 = *(char **)(pcStack_cc + 4);
    mm_free(pcStack_cc);
    pcStack_cc = pcVar13;
  }
  goto _L0;
_L241:
  uVar5 = 0x80;
  goto _L0;
_L0:
  uVar5 = 0;
  if (local_88[0] < uVar7) {
    local_70 = 0;
    uStack_6c = 0;
    uStack_68 = 0;
    uStack_64 = (void *)0x0;
    af_read_le8_isra_0(uVar18,local_88,&local_70);
    af_read_le16_isra_0(uVar18,local_88,(int)&local_70 + 2);
    if ((local_70 & 0xff) == 0) {
      af_read_le8_isra_0();
      af_read_le16_isra_0(uVar18,local_88,(int)&uStack_6c + 2);
      af_read_le16_isra_0(uVar18,local_88,&uStack_68);
      iVar9 = zcl_attr_type_is_analog(uStack_6c & 0xff);
      if (iVar9 != 0) {
        sVar11 = zcl_packet_read_variable_attr_size
                           (*(undefined4 *)(param_1 + 0x24),local_88[0],uStack_6c & 0xff);
        uStack_64 = calloc(1,sVar11);
        zcl_packet_read_variable_attr_value(uVar18,local_88,uStack_6c & 0xff,uStack_64);
      }
    }
    else {
      af_read_le16_isra_0(uVar18,local_88,&uStack_6c);
    }
    if (uVar7 < local_88[0]) {
      uVar5 = 0x80;
      goto _L0;
    }
    iVar9 = zcl_cluster_get_attr_desc(iVar4,local_70 >> 0x10,uVar24);
    if ((local_70 & 0xff) == 0) {
      if ((iVar9 == 0) || (*(int *)(iVar9 + 8) == 0)) {
        uVar17 = 0x86;
      }
      else {
        uVar8 = *(byte *)(iVar9 + 2) - 0x48;
        if ((9 < (uVar8 & 0xff)) || (uVar17 = 0x8c, (0x317U >> (uVar8 & 0x1f) & 1) == 0)) {
          if ((*(byte *)(iVar9 + 3) & 4) == 0) goto _L346;
          uVar17 = 0x8d;
          if ((uStack_6c & 0xff) == (uint)*(byte *)(iVar9 + 2)) {
            if (((uStack_68 & 0xffff) == 0) || (uStack_6c >> 0x10 <= (uStack_68 & 0xffff)))
            goto _L0;
            uVar17 = 0x87;
          }
        }
      }
_L0:
      zmsg_append_u8(iStack_34,uVar17);
      zmsg_append_u8(iStack_34,local_70 & 0xff);
      zmsg_append_le16(iStack_34,local_70 >> 0x10);
    }
    else {
      if (iVar9 == 0) {
_L346:
        uVar17 = 0x8c;
        goto _L0;
      }
_L0:
      pcVar13 = (char *)zcl_reporting_info_find
                                  (*(undefined1 *)(param_1 + 0x15),*(undefined2 *)(param_1 + 0x16),
                                   ((*(byte *)(param_1 + 0x1a) & 8) != 0) + '\x01',local_70 >> 0x10,
                                   *(undefined2 *)(iVar9 + 4));
      if (pcVar13 == (char *)0x0) {
        pcVar13 = (char *)zcl_reporting_info_create
                                    (*(undefined1 *)(param_1 + 0x15),*(undefined2 *)(param_1 + 0x18)
                                     ,(char)local_70 != '\0',*(undefined2 *)(param_1 + 0x16),
                                     ((*(byte *)(param_1 + 0x1a) & 8) != 0) + '\x01',
                                     local_70 >> 0x10,*(undefined2 *)(iVar9 + 4));
        zcl_reporting_info_add();
        iVar9 = err_to_zcl_status();
        if (iVar9 != 0) goto _L0;
      }
      if (*pcVar13 == '\0') {
        sVar2 = uStack_6c._2_2_;
        uVar5 = uStack_68 & 0xffff;
        *(short *)(pcVar13 + 0x10) = uStack_6c._2_2_;
        *(undefined2 *)(pcVar13 + 0x12) = (undefined2)uStack_68;
        iVar9 = zcl_attr_type_is_analog(uStack_6c & 0xff);
        if (iVar9 != 0) {
          if (uVar5 == 0) {
            if (sVar2 != -1) {
_L0:
              zcl_write_attr_value(pcVar13 + 0x18,uStack_64,uStack_6c & 0xff);
            }
          }
          else if (uVar5 != 0xffff) goto _L0;
        }
      }
      else {
        *(undefined2 *)(pcVar13 + 0x10) = (undefined2)uStack_6c;
      }
      zcl_reporting_info_update(pcVar13);
      uVar17 = err_to_zcl_status();
      zmsg_append_u8(iStack_34,uVar17);
    }
    if (uStack_64 != (void *)0x0) {
      mm_free();
      uStack_64 = (void *)0x0;
    }
    goto _L0;
  }
_L0:
  if (uStack_64 != (void *)0x0) {
    mm_free();
  }
  uVar18 = 7;
  if (uVar5 == 0) goto _L0;
  goto _L0;
_L0:
  if ((local_70 & 0xffff) < uVar5) {
    af_read_le8_isra_0(iVar4,&local_70,&uStack_110);
    af_read_le16_isra_0(iVar4,&local_70,(int)&uStack_110 + 2);
    if (uVar5 < (local_70 & 0xffff)) goto _L0;
    puVar16 = (undefined2 *)zcl_cluster_get_attr_desc(puVar15,uStack_110 >> 0x10,uVar24);
    iVar9 = 0x86;
    if ((puVar16 != (undefined2 *)0x0) && (*(int *)(puVar16 + 4) != 0)) {
      iVar9 = ((int)((uint)*(byte *)((int)puVar16 + 3) << 0x1d) >> 0x1f & 0xffffff74U) + 0x8c;
    }
    if (1 < (uStack_110 & 0xff)) {
      iVar9 = 0x87;
_L0:
      zmsg_append_u8(iStack_34,iVar9);
      zmsg_append_u8(iStack_34,uStack_110 & 0xff);
      uVar1 = uStack_110._2_2_;
      goto _L0;
    }
    if (iVar9 != 0) goto _L0;
    iVar3 = zcl_reporting_info_find
                      (*puVar14,*puVar15,*(undefined1 *)(puVar15 + 1),*puVar16,puVar16[2]);
    iVar9 = 0;
    if (iVar3 == 0) {
      iVar9 = 0x8b;
    }
    zmsg_append_u8(iStack_34,iVar9);
    zmsg_append_u8(iStack_34,uStack_110 & 0xff);
    zmsg_append_le16(iStack_34,uStack_110 >> 0x10);
    if (iVar9 == 0) {
      if ((uStack_110 & 0xff) == 0) {
        zmsg_append_u8(*(undefined1 *)(puVar16 + 1));
        zmsg_append_le16(iStack_34,*(undefined2 *)(iVar3 + 0x10));
        zmsg_append_le16(iStack_34,*(undefined2 *)(iVar3 + 0x12));
        iVar9 = zcl_attr_type_is_analog(*(undefined1 *)(puVar16 + 1));
        if (iVar9 != 0) {
          zcl_packet_append_variable_attr_value(iStack_34,*(undefined1 *)(puVar16 + 1),iVar3 + 0x18)
          ;
        }
      }
      else {
        uVar1 = *(undefined2 *)(iVar3 + 0x10);
_L0:
        zmsg_append_le16(iStack_34,uVar1);
      }
    }
    goto _L0;
  }
  uVar18 = 9;
  goto _L0;
_L0:
  uVar5 = 0x80;
  goto _L0;
_L0:
  if (local_88[0] < uVar5) {
    auStack_11c[0] = 0;
    af_read_le16_isra_0(iVar4,local_88,auStack_11c);
    psVar6 = (short *)zcl_get_attr_desc(*(undefined1 *)(param_1 + 0x15),
                                        *(undefined2 *)(param_1 + 0x16),
                                        ((*(byte *)(param_1 + 0x1a) & 8) != 0) + '\x01',
                                        auStack_11c[0],uVar24);
    bVar21 = 0x86;
    if (psVar6 != (short *)0x0) {
      bVar20 = *(byte *)((int)psVar6 + 3);
      bVar21 = 0x7e;
      if (((bVar20 & 1) != 0) && (bVar21 = bVar20 & 0x40, (bVar20 & 0x40) != 0)) {
        bVar21 = 0x7e;
      }
    }
    uVar7 = zcl_packet_max_available_space
                      (*(undefined2 *)(param_1 + 0x16),0,*(ushort *)(param_1 + 0x1a) >> 2 & 1);
    uVar8 = zmsg_get_length(iStack_34);
    if (uVar7 <= uVar8) {
      uVar5 = 0x89;
      goto _L0;
    }
    zmsg_append_le16(iStack_34,auStack_11c[0]);
    zmsg_append_u8(iStack_34,bVar21);
    if (bVar21 == 0) {
      zmsg_append_u8(iStack_34,(char)psVar6[1]);
      if (((*(short *)(param_1 + 0x16) == 10) && ((*(byte *)(param_1 + 0x1a) & 8) == 0)) &&
         (((ushort)(*psVar6 - 6U) < 2 || (*psVar6 == 0)))) {
        local_70 = 0;
        iVar9 = zcl_time_cluster_read_time(*(undefined1 *)(param_1 + 0x15),&local_70);
        if (iVar9 != 0) goto _L0;
        puVar19 = &local_70;
      }
      else {
        puVar19 = *(undefined4 **)(psVar6 + 4);
      }
      zcl_packet_append_variable_attr_value(iStack_34,(char)psVar6[1],puVar19);
    }
    goto _L0;
  }
  uVar18 = 1;
_L0:
  iVar4 = zcl_packet_setup_response(auStack_58,param_1,uVar18);
  goto _L0;
_L0:
  uVar5 = 0x8b;
  goto _L0;
_L0:
  uVar5 = 0x80;
  goto _L0;
_L0:
  if ((local_70 & 0xffff) < uVar5) {
    pvVar22 = calloc(1,0xc);
    *(void **)((int)pvVar22 + 8) = pvStack_f4;
    pvStack_f4 = pvVar22;
    af_read_le16_isra_0(uVar18,&local_70,pvVar22);
    af_read_le8_isra_0(uVar18,&local_70,(int)pvVar22 + 2);
    if (uVar5 < (local_70 & 0xffff)) goto _L0;
    if (*(char *)((int)pvVar22 + 2) == '\0') {
      af_read_le8_isra_0(uVar18,&local_70,(int)pvVar22 + 3);
      sVar11 = zcl_packet_read_variable_attr_size
                         (uVar18,local_70 & 0xffff,*(undefined1 *)((int)pvVar22 + 3));
      if (sVar11 == 0xffff) {
        uVar5 = 0x85;
        goto _L0;
      }
      pvVar10 = calloc(1,sVar11);
      *(void **)((int)pvVar22 + 4) = pvVar10;
      if ((pvVar10 == (void *)0x0) && (sVar11 != 0)) {
        uVar5 = 0x89;
        goto _L0;
      }
      zcl_packet_read_variable_attr_value
                (uVar18,&local_70,*(undefined1 *)((int)pvVar22 + 3),pvVar10);
    }
    goto _L0;
  }
  if ((*(short *)(param_1 + 0x16) != 10) ||
     (iVar4 = zcl_time_server_read_attr_rsp_handler(&uStack_100), iVar4 == 0)) {
    uStack_f0 = CONCAT31(uStack_f0._1_3_,0xfe);
    zcl_core_action_schedule(1,&uStack_100);
    uVar5 = uStack_f0 & 0xff;
    if (uVar5 != 0xfe) goto _L0;
  }
  uVar5 = 0;
_L0:
  while (pvStack_f4 != (void *)0x0) {
    pvVar22 = *(void **)((int)pvStack_f4 + 8);
    if (*(int *)((int)pvStack_f4 + 4) != 0) {
      mm_free();
    }
    mm_free(pvStack_f4);
    pvStack_f4 = pvVar22;
  }
_L0:
  iVar4 = zcl_packet_setup_default_response(auStack_58,param_1,uVar5);
_L0:
  if (iVar4 == 0) {
    zcl_packet_send(auStack_58,0);
  }
  else {
_L0:
    zcl_packet_free(auStack_58);
  }
  return iVar4;
}

