/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> thermostat_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t thermostat_cluster_srv_cmd_proc_handler(void *arg)

{
  uint8_t uVar1;
  short sVar2;
  uint8_t uVar3;
  _Bool _Var4;
  ezb_zcl_status_t eVar5;
  int iVar6;
  uint uVar7;
  undefined3 extraout_var;
  zcl_attr_desc_t *pzVar8;
  zcl_attr_desc_t *pzVar9;
  undefined3 extraout_var_00;
  int iVar10;
  undefined3 extraout_var_01;
  ezb_zcl_thermostat_weekly_schedule_transition_t *peVar11;
  weekly_schedule_context_t *pwVar12;
  uint16_t attr_id;
  weekly_schedule_graph_t **ppwVar13;
  uint8_t uVar14;
  weekly_schedule_graph_t *pwVar15;
  int iVar16;
  char cVar17;
  uint uVar18;
  int iVar19;
  ezb_zcl_thermostat_weekly_schedule_transition_t *peVar20;
  undefined1 uVar21;
  ezb_zcl_thermostat_setpoint_raise_or_lower_payload_t cool;
  weekly_schedule_graph_t *pwVar22;
  uint uVar23;
  weekly_schedule_graph_t **src;
  uint16_t uStack_92;
  undefined2 uStack_90;
  uint16_t offset_1;
  ezb_zcl_thermostat_setpoint_raise_or_lower_payload_t payload;
  uint16_t offset;
  int16_t min_value;
  undefined4 uStack_84;
  int16_t max_value;
  void *pvStack_7c;
  ezb_zcl_thermostat_setpoint_raise_or_lower_payload_t *peStack_78;
  uint uStack_74;
  undefined1 auStack_68 [4];
  zcl_packet_t rsp;
  
  memset(auStack_68,0,0x28);
  if (arg == (void *)0x0) {
    iVar6 = 1;
    goto _L0;
  }
  iVar6 = 1;
  if (((*(byte *)((int)arg + 0x1a) >> 3 & 1) != 0) ||
     (iVar6 = zcl_packet_init(auStack_68,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar6 != 0))
  goto _L0;
  uVar18 = (uint)*(byte *)((int)arg + 0x20);
  if (uVar18 == 2) {
    uStack_84 = (weekly_schedule_graph_t *)((uint)uStack_84._2_2_ << 0x10);
    _payload = (uint)offset << 0x10;
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),(uint16_t *)&uStack_84,&payload.mode);
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),(uint16_t *)&uStack_84,(uint8_t *)&payload.amount);
    uVar18 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
    if (uVar18 < ((uint)uStack_84 & 0xffff)) {
      iVar10 = 0x80;
    }
    else {
      cVar17 = '\0';
      for (uVar18 = _payload & 0xff; uVar18 != 0; uVar18 = uVar18 & uVar18 - 1) {
        cVar17 = cVar17 + '\x01';
      }
      iVar10 = 0x85;
      if (cVar17 == '\x01') {
        pwVar12 = thermostat_weekly_schedule_context_get(*(uint8_t *)((int)arg + 0x15));
        zmsg_append_u8((zmsg_t *)rsp._32_4_,'\0');
        zmsg_append_u8((zmsg_t *)rsp._32_4_,payload.mode);
        zmsg_append_u8((zmsg_t *)rsp._32_4_,payload.amount);
        uVar18 = 0;
        do {
          uVar21 = 0;
          if (((int)(_payload & 0xff) >> (uVar18 & 0x1f) & 1U) != 0) {
            pwVar15 = pwVar12->graph[uVar18];
            uVar18 = 0;
            if (pwVar15 != (weekly_schedule_graph_t *)0x0) goto _L0;
            break;
          }
          uVar18 = uVar18 + 1;
        } while (uVar18 != 7);
_L0:
        offset_1 = CONCAT11(offset_1._1_1_,uVar21);
        zmsg_write_bytes(rsp._32_4_,0,1,&offset_1);
        zcl_packet_setup_response(auStack_68,arg,0);
        goto _L0;
      }
    }
    zcl_packet_setup_default_response(auStack_68,arg,iVar10);
  }
  else {
    if (uVar18 < 3) {
      if (uVar18 == 0) {
        offset_1 = 0;
        _payload = (uint)offset << 0x10;
        uStack_84 = (weekly_schedule_graph_t *)((uint)uStack_84._2_2_ << 0x10);
        uStack_90 = 0;
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_1,(uint8_t *)&uStack_90);
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_1,(uint8_t *)((int)&uStack_90 + 1));
        uVar23 = 0x80;
        uVar7 = zcl_packet_payload_get_length(*(undefined4 *)((int)arg + 0x24));
        uVar18 = (uint)offset_1;
        if (uVar7 < uVar18) goto _L0;
        uVar1 = *(uint8_t *)((int)arg + 0x15);
        _Var4 = thermostat_is_occupied(uVar1);
        if (CONCAT31(extraout_var,_Var4) == 0) {
          pzVar8 = thermostat_srv_get_attr_desc(uVar1,0x14);
          attr_id = 0x13;
        }
        else {
          pzVar8 = thermostat_srv_get_attr_desc(uVar1,0x12);
          attr_id = 0x11;
        }
        pzVar9 = thermostat_srv_get_attr_desc(uVar1,attr_id);
        if (pzVar8 == (zcl_attr_desc_t *)0x0) {
          uVar23 = 0;
          iVar10 = 0;
          if (pzVar9 == (zcl_attr_desc_t *)0x0) {
            __assert_func(0,0,0);
            goto _L0;
          }
_L0:
                    /* WARNING: Load size is inaccurate */
          uVar18 = (uint)*pzVar9->data_p;
        }
        else {
          uVar18 = 0;
                    /* WARNING: Load size is inaccurate */
          uVar23 = (uint)*pzVar8->data_p;
          iVar10 = (int)(short)*pzVar8->data_p;
          if (pzVar9 != (zcl_attr_desc_t *)0x0) goto _L0;
        }
        cool = SUB42(uVar18,0);
        if ((uint8_t)uStack_90 == '\x01') {
          thermostat_get_cool_setpoint_limit(uVar1,(int16_t *)&payload,(int16_t *)&uStack_84);
          iVar19 = uStack_90._1_1_ * 10;
          iVar16 = iVar19 + (short)cool;
          cool = uStack_84._0_2_;
          if ((iVar16 <= (short)uStack_84._0_2_) && (cool = payload, (short)payload <= iVar16)) {
_L0:
            cool = SUB42((uVar18 + iVar19) * 0x10000 >> 0x10,0);
          }
        }
        else if ((uint8_t)uStack_90 == '\x02') {
          thermostat_get_heat_setpoint_limit(uVar1,(int16_t *)&payload,(int16_t *)&uStack_84);
          iVar16 = uStack_90._1_1_ * 10 + iVar10;
          iVar10 = (int)(short)uStack_84._0_2_;
          if (iVar16 <= iVar10) {
            iVar10 = (int)(short)payload;
            if (iVar10 <= iVar16) {
              iVar10 = (int)((uVar23 + uStack_90._1_1_ * 10) * 0x10000) >> 0x10;
            }
          }
          thermostat_get_cool_setpoint_limit(uVar1,(int16_t *)&payload,(int16_t *)&uStack_84);
          iVar19 = uStack_90._1_1_ * 10;
          iVar16 = iVar19 + (short)cool;
          cool = uStack_84._0_2_;
          if ((iVar16 <= (short)uStack_84._0_2_) && (cool = payload, (short)payload <= iVar16))
          goto _L0;
        }
        else if ((uint8_t)uStack_90 == '\0') {
          thermostat_get_heat_setpoint_limit(uVar1,(int16_t *)&payload,(int16_t *)&uStack_84);
          iVar16 = uStack_90._1_1_ * 10 + iVar10;
          iVar10 = (int)(short)uStack_84._0_2_;
          if (iVar16 <= iVar10) {
            iVar10 = (int)(short)payload;
            if (iVar10 <= iVar16) {
              iVar10 = (int)((uVar23 + uStack_90._1_1_ * 10) * 0x10000) >> 0x10;
            }
          }
        }
        eVar5 = zcl_message_thermostat_setpoint
                          (uVar1,(uint8_t)uStack_90,(int16_t)iVar10,(int16_t)cool);
        uVar23 = CONCAT31(extraout_var_00,eVar5);
        if (uVar23 == 0) {
          thermostat_set_heat_cool_value(uVar1,(uint8_t)uStack_90,(int16_t)iVar10,(int16_t)cool);
        }
      }
      else {
        uVar1 = *(uint8_t *)((int)arg + 0x15);
        uStack_92 = 0;
        _payload = 0;
        _min_value = (void *)0x0;
        uVar18 = zmsg_get_length();
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_92,&payload.mode);
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_92,(uint8_t *)&payload.amount);
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_92,(uint8_t *)&offset);
        uVar23 = 0x87;
        if (payload.mode < 0xb) {
          _min_value = calloc(1,0x3c);
          uVar23 = 0x89;
          if (_min_value != (void *)0x0) {
            for (uVar23 = 0; (uStack_92 < uVar18 && (uVar23 < (_payload & 0xff)));
                uVar23 = uVar23 + 1 & 0xff) {
              iVar10 = uVar23 * 6;
              af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_92,
                           (uint16_t *)((int)_min_value + iVar10));
              if ((_payload & 0x10000) != 0) {
                af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_92,
                             (uint16_t *)((int)_min_value + iVar10 + 2));
              }
              if ((_payload & 0x20000) != 0) {
                af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_92,
                             (uint16_t *)((int)_min_value + iVar10 + 4));
              }
            }
            uStack_84 = (weekly_schedule_graph_t *)0x0;
            _max_value = 0;
            pvStack_7c = (void *)0x0;
            peStack_78 = (ezb_zcl_thermostat_setpoint_raise_or_lower_payload_t *)0x0;
            uStack_74 = 0;
            uVar23 = zcl_packet_to_message(&uStack_84,arg);
            if (uVar23 == 0) {
              uStack_74 = CONCAT31(uStack_74._1_3_,0xfe);
              pvStack_7c = arg;
              peStack_78 = &payload;
              zcl_core_action_schedule(0x38,&uStack_84);
              uVar23 = uStack_74 & 0xff;
              if ((uVar23 == 0xfe) || (uVar23 == 0)) {
                pwVar15 = (weekly_schedule_graph_t *)0x1c;
                memset(&uStack_84,0,0x1c);
                pwVar12 = thermostat_weekly_schedule_context_get(uVar1);
                src = pwVar12->graph;
                eVar5 = thermostat_weekly_schedule_graphs_copy
                                  ((weekly_schedule_graph_t **)&uStack_84,src,(uint8_t)pwVar15);
                if (CONCAT31(extraout_var_01,eVar5) == 0) {
                  for (pwVar22 = (weekly_schedule_graph_t *)0x0;
                      pwVar15 = (weekly_schedule_graph_t *)(_payload & 0xff), pwVar22 < pwVar15;
                      pwVar22 = (weekly_schedule_graph_t *)
                                ((uint)&pwVar22->num_of_transition & 0xff)) {
                    if ((_payload & 0x10000) != 0) {
                      pwVar15 = (weekly_schedule_graph_t *)&offset_1;
                      sVar2 = *(short *)((int)_min_value + (int)pwVar22 * 6 + 2);
                      thermostat_get_heat_setpoint_limit(uVar1,&uStack_90,(int16_t *)pwVar15);
                      if ((uStack_90 <= sVar2) && (sVar2 <= (short)offset_1)) goto _L0;
_L0:
                      uVar23 = 0x87;
                      goto _L0;
                    }
_L0:
                    if ((_payload & 0x20000) != 0) {
                      pwVar15 = (weekly_schedule_graph_t *)&offset_1;
                      sVar2 = *(short *)((int)_min_value + (int)pwVar22 * 6 + 4);
                      thermostat_get_cool_setpoint_limit(uVar1,&uStack_90,(int16_t *)pwVar15);
                      if (((sVar2 < uStack_90) || ((short)offset_1 < sVar2)) ||
                         (*(short *)((int)_min_value + (int)pwVar22 * 6 + 4) != sVar2)) goto _L0;
                    }
                  }
                  uVar7 = 0;
                  uVar23 = 0;
                  uVar18 = 0;
                  ppwVar13 = src;
                  do {
                    if (*ppwVar13 == (weekly_schedule_graph_t *)0x0) break;
                    if (((int)(_payload >> 8 & 0xff) >> (uVar18 & 0x1f) & 1U) != 0) {
                      uVar7 = uVar7 + 1 & 0xff;
                      uVar23 = uVar23 + (*ppwVar13)->num_of_transition & 0xff;
                    }
                    uVar18 = uVar18 + 1;
                    ppwVar13 = ppwVar13 + 1;
                  } while (uVar18 != 7);
                  if (((weekly_schedule_graph_t *)(uint)pwVar12->daily_limit < pwVar15) ||
                     ((uint)pwVar12->weekly_limit < uVar7 * (int)pwVar15 + uVar23)) goto _L0;
                  uVar18 = 0;
                  ppwVar13 = src;
                  do {
                    if (((int)(_payload >> 8 & 0xff) >> (uVar18 & 0x1f) & 1U) != 0) {
                      thermostat_weekly_schedule_graphs_free(ppwVar13,'\x01');
                      uVar3 = (uint8_t)offset;
                      uVar14 = payload.mode;
                      uVar23 = _payload & 0xff;
                      pwVar22 = (weekly_schedule_graph_t *)calloc(1,8);
                      if (pwVar22 == (weekly_schedule_graph_t *)0x0) {
                        pwVar12->graph[uVar18] = (weekly_schedule_graph_t *)0x0;
                        goto _L0;
                      }
                      pwVar22->num_of_transition = uVar14;
                      pwVar22->mode_of_transition = uVar3;
                      peVar11 = (ezb_zcl_thermostat_weekly_schedule_transition_t *)calloc(uVar23,6);
                      pwVar22->transitions = peVar11;
                      *ppwVar13 = pwVar22;
                      memcpy(peVar11,_min_value,uVar23 * 6);
                      qsort((*ppwVar13)->transitions,(uint)(*ppwVar13)->num_of_transition,6,
                            compare_by_transition_start_time);
                      pwVar15 = *ppwVar13;
                      if (pwVar15 != (weekly_schedule_graph_t *)0x0) {
                        for (uVar23 = 0;
                            ((uVar23 & 0xff) < (uint)pwVar15->num_of_transition &&
                            (((uVar23 & 0xff) + 1 & 0xff) < (uint)pwVar15->num_of_transition));
                            uVar23 = uVar23 + 1) {
                          peVar11 = pwVar15->transitions + uVar23;
                          peVar20 = pwVar15->transitions + uVar23 + 1;
                          if ((peVar11->start_time == peVar20->start_time) &&
                             ((peVar11->heat_setpoint == peVar20->heat_setpoint &&
                              (peVar11->cool_setpoint == peVar20->cool_setpoint)))) {
                            uVar23 = 1;
                            goto _L0;
                          }
                        }
                      }
                    }
                    uVar18 = uVar18 + 1;
                    ppwVar13 = ppwVar13 + 1;
                    uVar23 = 0;
                  } while (uVar18 != 7);
                }
                else {
_L0:
                  uVar23 = 0x89;
_L0:
                  uVar14 = (uint8_t)pwVar15;
                  thermostat_weekly_schedule_graphs_free(src,'\a');
                  thermostat_weekly_schedule_graphs_copy
                            (src,(weekly_schedule_graph_t **)&uStack_84,uVar14);
                }
                thermostat_weekly_schedule_graphs_free((weekly_schedule_graph_t **)&uStack_84,'\a');
                if (uVar23 == 0) {
                  thermostat_weekly_schedule_loop_start(uVar1);
                }
              }
            }
          }
        }
        if (_min_value != (void *)0x0) {
          mm_free();
        }
      }
    }
    else {
_L0:
      if (uVar18 == 3) {
        pwVar12 = thermostat_weekly_schedule_context_get(*(uint8_t *)((int)arg + 0x15));
        if (pwVar12 != (weekly_schedule_context_t *)0x0) {
          thermostat_weekly_schedule_loop_stop(pwVar12->ep_id);
          thermostat_weekly_schedule_graphs_free(pwVar12->graph,'\a');
        }
        uVar23 = 0;
      }
      else {
        uVar23 = 0x81;
      }
    }
_L0:
    iVar10 = zcl_packet_setup_default_response(auStack_68,arg,uVar23);
    if (iVar10 == 0) {
_L0:
      zcl_packet_send(auStack_68,0);
      goto _L0;
    }
  }
  zcl_packet_free(auStack_68);
  iVar6 = iVar10;
_L0:
  return (ezb_zcl_status_t)iVar6;
_L0:
  uVar21 = (undefined1)uVar18;
  if ((uint)pwVar15->num_of_transition <= (uVar18 & 0xff)) goto _L0;
  if (uVar18 == 10) {
    uVar21 = 10;
    goto _L0;
  }
  zmsg_append_le16((zmsg_t *)rsp._32_4_,pwVar15->transitions[uVar18].start_time);
  if ((_payload & 0x100) != 0) {
    zmsg_append_le16((zmsg_t *)rsp._32_4_,pwVar15->transitions[uVar18].heat_setpoint);
  }
  if ((_payload & 0x200) != 0) {
    zmsg_append_le16((zmsg_t *)rsp._32_4_,pwVar15->transitions[uVar18].cool_setpoint);
  }
  uVar18 = uVar18 + 1;
  goto _L0;
}

