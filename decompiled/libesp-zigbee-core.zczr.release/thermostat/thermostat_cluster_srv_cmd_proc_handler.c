/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> thermostat_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int thermostat_cluster_srv_cmd_proc_handler(int param_1)

{
  short sVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  void *__dest;
  undefined1 *puVar7;
  undefined4 uVar8;
  int *piVar9;
  short *psVar10;
  int iVar11;
  char cVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  short *psVar16;
  undefined1 uVar17;
  uint uVar18;
  int *piVar19;
  ushort uStack_92;
  undefined2 uStack_90;
  ushort uStack_8e;
  undefined4 uStack_8c;
  void *pvStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  int iStack_7c;
  undefined4 *puStack_78;
  uint uStack_74;
  undefined1 auStack_68 [36];
  undefined4 uStack_44;
  
  memset(auStack_68,0,0x28);
  if (param_1 == 0) {
    return 1;
  }
  if ((*(byte *)(param_1 + 0x1a) >> 3 & 1) != 0) {
    return 1;
  }
  iVar4 = zcl_packet_init(auStack_68,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar4 != 0) {
    return iVar4;
  }
  uVar13 = (uint)*(byte *)(param_1 + 0x20);
  if (uVar13 == 2) {
    uStack_84 = (uint)uStack_84._2_2_ << 0x10;
    uStack_8c = (uint)uStack_8c._2_2_ << 0x10;
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_84,&uStack_8c);
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_84,(int)&uStack_8c + 1);
    uVar13 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uVar13 < (uStack_84 & 0xffff)) {
      iVar4 = 0x80;
    }
    else {
      cVar12 = '\0';
      for (uVar13 = uStack_8c & 0xff; uVar13 != 0; uVar13 = uVar13 & uVar13 - 1) {
        cVar12 = cVar12 + '\x01';
      }
      iVar4 = 0x85;
      if (cVar12 == '\x01') {
        iVar4 = thermostat_weekly_schedule_context_get(*(undefined1 *)(param_1 + 0x15));
        zmsg_append_u8(uStack_44,0);
        zmsg_append_u8(uStack_44,uStack_8c & 0xff);
        zmsg_append_u8(uStack_44,uStack_8c >> 8 & 0xff);
        uVar13 = 0;
        do {
          uVar17 = 0;
          if (((int)(uStack_8c & 0xff) >> (uVar13 & 0x1f) & 1U) != 0) {
            iVar4 = *(int *)(iVar4 + uVar13 * 4 + 8);
            uVar13 = 0;
            if (iVar4 != 0) goto _L0;
            break;
          }
          uVar13 = uVar13 + 1;
        } while (uVar13 != 7);
_L0:
        uStack_8e = CONCAT11(uStack_8e._1_1_,uVar17);
        zmsg_write_bytes(uStack_44,0,1,&uStack_8e);
        zcl_packet_setup_response(auStack_68,param_1,0);
        goto _L0;
      }
    }
    zcl_packet_setup_default_response(auStack_68,param_1,iVar4);
    goto _L0;
  }
  if (uVar13 < 3) {
    if (uVar13 == 0) {
      uStack_8e = 0;
      uStack_8c = (uint)uStack_8c._2_2_ << 0x10;
      uStack_84 = (uint)uStack_84._2_2_ << 0x10;
      uStack_90 = 0;
      af_read_le8_isra_0(&uStack_8e,&uStack_90);
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_8e,(int)&uStack_90 + 1);
      uVar18 = 0x80;
      uVar5 = zcl_packet_payload_get_length(*(undefined4 *)(param_1 + 0x24));
      uVar13 = (uint)uStack_8e;
      if (uVar5 < uVar13) goto _L0;
      uVar17 = *(undefined1 *)(param_1 + 0x15);
      iVar4 = thermostat_is_occupied(uVar17);
      if (iVar4 == 0) {
        iVar4 = thermostat_srv_get_attr_desc(uVar17,0x14);
        uVar8 = 0x13;
      }
      else {
        iVar4 = thermostat_srv_get_attr_desc(uVar17,0x12);
        uVar8 = 0x11;
      }
      iVar6 = thermostat_srv_get_attr_desc(uVar17,uVar8);
      if (iVar4 == 0) {
        uVar18 = 0;
        iVar4 = 0;
        if (iVar6 == 0) {
          __assert_func(0,0,0);
          goto _L0;
        }
_L0:
        uVar13 = (uint)**(ushort **)(iVar6 + 8);
      }
      else {
        uVar13 = 0;
        uVar18 = (uint)**(ushort **)(iVar4 + 8);
        iVar4 = (int)(short)**(ushort **)(iVar4 + 8);
        if (iVar6 != 0) goto _L0;
      }
      iVar6 = (int)(short)uVar13;
      if ((char)uStack_90 == '\x01') {
        thermostat_get_cool_setpoint_limit_part_0(uVar17,&uStack_8c,&uStack_84);
        iVar14 = uStack_90._1_1_ * 10;
        iVar11 = iVar14 + iVar6;
        iVar6 = (int)(short)uStack_84;
        if (iVar11 <= iVar6) {
          iVar6 = (int)(short)uStack_8c;
          if (iVar6 <= iVar11) {
_L0:
            iVar6 = (int)((uVar13 + iVar14) * 0x10000) >> 0x10;
          }
        }
      }
      else if ((char)uStack_90 == '\x02') {
        thermostat_get_heat_setpoint_limit_part_0(uVar17,&uStack_8c,&uStack_84);
        iVar11 = uStack_90._1_1_ * 10 + iVar4;
        iVar4 = (int)(short)uStack_84;
        if (iVar11 <= iVar4) {
          iVar4 = (int)(short)uStack_8c;
          if (iVar4 <= iVar11) {
            iVar4 = (int)((uVar18 + uStack_90._1_1_ * 10) * 0x10000) >> 0x10;
          }
        }
        thermostat_get_cool_setpoint_limit_part_0(uVar17,&uStack_8c,&uStack_84);
        iVar14 = uStack_90._1_1_ * 10;
        iVar11 = iVar14 + iVar6;
        iVar6 = (int)(short)uStack_84;
        if (iVar11 <= iVar6) {
          iVar6 = (int)(short)uStack_8c;
          if (iVar6 <= iVar11) goto _L0;
        }
      }
      else if ((char)uStack_90 == '\0') {
        thermostat_get_heat_setpoint_limit_part_0(uVar17,&uStack_8c,&uStack_84);
        iVar11 = uStack_90._1_1_ * 10 + iVar4;
        iVar4 = (int)(short)uStack_84;
        if (iVar11 <= iVar4) {
          iVar4 = (int)(short)uStack_8c;
          if (iVar4 <= iVar11) {
            iVar4 = (int)((uVar18 + uStack_90._1_1_ * 10) * 0x10000) >> 0x10;
          }
        }
      }
      uVar18 = zcl_message_thermostat_setpoint(uVar17,(char)uStack_90,iVar4,iVar6);
      if (uVar18 == 0) {
        thermostat_set_heat_cool_value(uVar17,(char)uStack_90,iVar4,iVar6);
      }
    }
    else {
      uVar17 = *(undefined1 *)(param_1 + 0x15);
      uStack_92 = 0;
      uStack_8c = 0;
      pvStack_88 = (void *)0x0;
      uVar13 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_92,&uStack_8c);
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_92,(int)&uStack_8c + 1);
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_92,(int)&uStack_8c + 2);
      uVar18 = 0x87;
      if ((byte)uStack_8c < 0xb) {
        pvStack_88 = calloc(1,0x3c);
        uVar18 = 0x89;
        if (pvStack_88 != (void *)0x0) {
          for (uVar18 = 0; (uStack_92 < uVar13 && (uVar18 < (uStack_8c & 0xff)));
              uVar18 = uVar18 + 1 & 0xff) {
            iVar4 = uVar18 * 6;
            af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_92,
                                (void *)((int)pvStack_88 + iVar4));
            if ((uStack_8c & 0x10000) != 0) {
              af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_92,
                                  (int)pvStack_88 + iVar4 + 2);
            }
            if ((uStack_8c & 0x20000) != 0) {
              af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_92,
                                  (int)pvStack_88 + iVar4 + 4);
            }
          }
          uStack_84 = 0;
          uStack_80 = 0;
          iStack_7c = 0;
          puStack_78 = (undefined4 *)0x0;
          uStack_74 = 0;
          uVar18 = zcl_packet_to_message(&uStack_84,param_1);
          if (uVar18 == 0) {
            uStack_74 = CONCAT31(uStack_74._1_3_,0xfe);
            iStack_7c = param_1;
            puStack_78 = &uStack_8c;
            zcl_core_action_schedule(0x39,&uStack_84);
            uVar18 = uStack_74 & 0xff;
            if ((uVar18 == 0xfe) || (uVar18 == 0)) {
              memset(&uStack_84,0,0x1c);
              iVar4 = thermostat_weekly_schedule_context_get(uVar17);
              piVar19 = (int *)(iVar4 + 8);
              iVar6 = thermostat_weekly_schedule_graphs_copy_constprop_0(&uStack_84,piVar19);
              if (iVar6 == 0) {
                for (uVar13 = 0; uVar18 = uStack_8c & 0xff, uVar13 < uVar18;
                    uVar13 = uVar13 + 1 & 0xff) {
                  if ((uStack_8c & 0x10000) != 0) {
                    sVar1 = *(short *)((int)pvStack_88 + uVar13 * 6 + 2);
                    thermostat_get_heat_setpoint_limit_part_0(uVar17,&uStack_90,&uStack_8e);
                    if ((uStack_90 <= sVar1) && (sVar1 <= (short)uStack_8e)) goto _L0;
_L0:
                    uVar18 = 0x87;
                    goto _L0;
                  }
_L0:
                  if ((uStack_8c & 0x20000) != 0) {
                    sVar1 = *(short *)((int)pvStack_88 + uVar13 * 6 + 4);
                    thermostat_get_cool_setpoint_limit_part_0(uVar17,&uStack_90,&uStack_8e);
                    if (((sVar1 < uStack_90) || ((short)uStack_8e < sVar1)) ||
                       (*(short *)((int)pvStack_88 + uVar13 * 6 + 4) != sVar1)) goto _L0;
                  }
                }
                uVar15 = 0;
                uVar5 = 0;
                uVar13 = 0;
                piVar9 = piVar19;
                do {
                  if (*piVar9 == 0) break;
                  if (((int)(uStack_8c >> 8 & 0xff) >> (uVar13 & 0x1f) & 1U) != 0) {
                    uVar15 = uVar15 + 1 & 0xff;
                    uVar5 = uVar5 + *(byte *)(*piVar9 + 1) & 0xff;
                  }
                  uVar13 = uVar13 + 1;
                  piVar9 = piVar9 + 1;
                } while (uVar13 != 7);
                if ((*(byte *)(iVar4 + 4) < uVar18) ||
                   ((uint)*(byte *)(iVar4 + 3) < uVar15 * uVar18 + uVar5)) goto _L0;
                uVar13 = 0;
                piVar9 = piVar19;
                do {
                  if (((int)(uStack_8c >> 8 & 0xff) >> (uVar13 & 0x1f) & 1U) != 0) {
                    thermostat_weekly_schedule_graphs_free(piVar9,1);
                    uVar3 = uStack_8c._2_1_;
                    uVar2 = (byte)uStack_8c;
                    uVar18 = uStack_8c & 0xff;
                    puVar7 = (undefined1 *)calloc(1,8);
                    if (puVar7 == (undefined1 *)0x0) {
                      *(undefined4 *)(uVar13 * 4 + iVar4 + 8) = 0;
                      goto _L0;
                    }
                    puVar7[1] = uVar2;
                    *puVar7 = uVar3;
                    __dest = calloc(uVar18,6);
                    *(void **)(puVar7 + 4) = __dest;
                    *piVar9 = (int)puVar7;
                    memcpy(__dest,pvStack_88,uVar18 * 6);
                    qsort(*(void **)(*piVar9 + 4),(uint)*(byte *)(*piVar9 + 1),6,
                          compare_by_transition_start_time);
                    iVar6 = *piVar9;
                    if (iVar6 != 0) {
                      for (uVar18 = 0;
                          ((uVar18 & 0xff) < (uint)*(byte *)(iVar6 + 1) &&
                          (((uVar18 & 0xff) + 1 & 0xff) < (uint)*(byte *)(iVar6 + 1)));
                          uVar18 = uVar18 + 1) {
                        psVar10 = (short *)(*(int *)(iVar6 + 4) + uVar18 * 6);
                        psVar16 = (short *)(*(int *)(iVar6 + 4) + uVar18 * 6 + 6);
                        if ((*psVar10 == *psVar16) &&
                           ((psVar10[1] == psVar16[1] && (psVar10[2] == psVar16[2])))) {
                          uVar18 = 1;
                          goto _L0;
                        }
                      }
                    }
                  }
                  uVar13 = uVar13 + 1;
                  piVar9 = piVar9 + 1;
                  uVar18 = 0;
                } while (uVar13 != 7);
              }
              else {
_L0:
                uVar18 = 0x89;
_L0:
                thermostat_weekly_schedule_graphs_free(piVar19,7);
                thermostat_weekly_schedule_graphs_copy_constprop_0(piVar19,&uStack_84);
              }
              thermostat_weekly_schedule_graphs_free(&uStack_84,7);
              if (uVar18 == 0) {
                thermostat_weekly_schedule_loop_start(uVar17);
              }
            }
          }
        }
      }
      if (pvStack_88 != (void *)0x0) {
        mm_free();
      }
    }
  }
  else {
_L0:
    if (uVar13 == 3) {
      puVar7 = (undefined1 *)thermostat_weekly_schedule_context_get(*(undefined1 *)(param_1 + 0x15))
      ;
      if (puVar7 != (undefined1 *)0x0) {
        thermostat_weekly_schedule_loop_stop(*puVar7);
        thermostat_weekly_schedule_graphs_free(puVar7 + 8,7);
      }
      uVar18 = 0;
    }
    else {
      uVar18 = 0x81;
    }
  }
_L0:
  iVar4 = zcl_packet_setup_default_response(auStack_68,param_1,uVar18);
  if (iVar4 == 0) {
_L0:
    zcl_packet_send(auStack_68,0);
    return 0;
  }
_L0:
  zcl_packet_free(auStack_68);
  return iVar4;
_L0:
  uVar17 = (undefined1)uVar13;
  if ((uint)*(byte *)(iVar4 + 1) <= (uVar13 & 0xff)) goto _L0;
  if (uVar13 == 10) {
    uVar17 = 10;
    goto _L0;
  }
  iVar6 = uVar13 * 6;
  zmsg_append_le16(uStack_44,*(undefined2 *)(*(int *)(iVar4 + 4) + iVar6));
  if ((uStack_8c & 0x100) != 0) {
    zmsg_append_le16(uStack_44,*(undefined2 *)(*(int *)(iVar4 + 4) + iVar6 + 2));
  }
  if ((uStack_8c & 0x200) != 0) {
    zmsg_append_le16(uStack_44,*(undefined2 *)(*(int *)(iVar4 + 4) + iVar6 + 4));
  }
  uVar13 = uVar13 + 1;
  goto _L0;
}

