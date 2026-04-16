/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> color_control.o -> color_control_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t color_control_cluster_srv_cmd_proc_handler(void *arg)

{
  int32_t iVar1;
  int iVar2;
  _Bool _Var3;
  ezb_zcl_status_t eVar4;
  byte bVar5;
  zcl_attr_desc_t *pzVar6;
  uint uVar7;
  zmsg_t *payload;
  uint uVar8;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  zcl_attr_desc_t *pzVar9;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  undefined3 extraout_var_08;
  undefined3 extraout_var_09;
  undefined3 extraout_var_10;
  undefined3 extraout_var_11;
  undefined3 extraout_var_12;
  undefined3 extraout_var_13;
  undefined3 extraout_var_14;
  undefined3 extraout_var_15;
  undefined3 extraout_var_16;
  undefined3 extraout_var_17;
  undefined3 extraout_var_18;
  undefined3 extraout_var_19;
  undefined3 extraout_var_20;
  undefined3 extraout_var_21;
  undefined3 extraout_var_22;
  undefined3 extraout_var_23;
  undefined3 extraout_var_24;
  undefined3 extraout_var_25;
  undefined3 extraout_var_26;
  undefined3 extraout_var_27;
  undefined3 extraout_var_28;
  undefined3 extraout_var_29;
  undefined3 extraout_var_30;
  undefined3 extraout_var_31;
  zcl_attr_desc_t *pzVar10;
  zcl_attr_desc_t *pzVar11;
  zcl_attr_desc_t *pzVar12;
  uint8_t mode;
  uint16_t remaining_time;
  ushort uVar13;
  uint8_t uVar14;
  uint16_t uStack_a4;
  uint16_t uStack_a2;
  uint16_t offset_15;
  uint16_t offset_3;
  uint16_t offset;
  undefined2 uStack_9a;
  undefined1 auStack_98 [4];
  ezb_zcl_color_control_color_loop_set_cmd_payload_t req;
  undefined1 auStack_78 [4];
  zcl_cvc_input_t input;
  zcl_packet_t rsp;
  
  memset(&input.data,0,0x28);
  if ((arg != (void *)0x0) && ((*(byte *)((int)arg + 0x1a) >> 3 & 1) == 0)) {
    bVar5 = *(byte *)((int)arg + 0x20);
    pzVar6 = color_control_srv_get_attr_desc(*(uint8_t *)((int)arg + 0x15),0x400a);
    if (pzVar6 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
      uVar13 = *pzVar6->data_p;
      if (bVar5 < 0x44) {
        if (bVar5 < 0x40) {
          if (bVar5 < 10) {
            if (6 < bVar5) {
              uVar13 = uVar13 >> 3;
            }
          }
          else {
            if (bVar5 != 10) goto _L0;
_L0:
            uVar13 = uVar13 >> 4;
          }
        }
        else {
          uVar13 = uVar13 >> 1;
        }
_L0:
        if ((uVar13 & 1) != 0) {
_L0:
          uVar7 = zcl_packet_init(&input.data,*(ushort *)((int)arg + 0x1a) >> 2 & 1);
          if (uVar7 != 0) goto _L0;
          bVar5 = *(byte *)((int)arg + 0x20);
          uVar7 = 0;
          if (bVar5 == 10) {
            uStack_a4 = 0;
            auStack_98 = (undefined1  [4])0x0;
            req._0_4_ = (uint)(ushort)req._2_2_ << 0x10;
            af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_a4,(uint16_t *)auStack_98);
            af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_a4,(uint16_t *)(auStack_98 + 2));
            uVar8 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
            if (uVar8 < uStack_a4) goto _L0;
            af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_a4,&req.update_flags);
            af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_a4,&req.action);
            _Var3 = color_control_check_options_is_exec
                              (*(uint8_t *)((int)arg + 0x15),req.update_flags,req.action);
            if (CONCAT31(extraout_var_16,_Var3) != 0) {
              eVar4 = color_control_change_color_mode((zcl_packet_t *)arg,'\x02');
              uVar7 = CONCAT31(extraout_var_17,eVar4);
              if (uVar7 == 0) {
                uVar14 = *(uint8_t *)((int)arg + 0x15);
                memset(auStack_78,0,0x18);
                input.end._0_2_ = 1;
                input._12_4_ = (uint)auStack_98 >> 0x10;
                auStack_78[0] = uVar14;
                input._20_4_ = cvc_color_temperature_output_handler;
                input.cb = (zcl_cvc_output_callback_t)0x7;
                pzVar6 = color_control_srv_get_attr_desc(uVar14,7);
                if (pzVar6 == (zcl_attr_desc_t *)0x0) goto _L0;
                color_control_get_color_temperature_range(uVar14,&uStack_a2,&offset_15);
                    /* WARNING: Load size is inaccurate */
                input._0_4_ = ZEXT24(*pzVar6->data_p);
                input.begin = (uint)auStack_98 & 0xffff;
                if (((uint)auStack_98 & 0xffff) < (uint)uStack_a2) {
                  input.begin = (uint)uStack_a2;
                }
                if ((_offset_15 & 0xffff) < (uint)input.begin) {
                  input.begin = _offset_15 & 0xffff;
                }
_L0:
                bVar5 = schedule_cvc_color_line(uVar14,(zcl_cvc_input_t *)auStack_78);
_L0:
                uVar7 = (uint)bVar5;
              }
            }
_L0:
            uVar7 = zcl_packet_setup_default_response(&input.data,arg,uVar7);
            if (uVar7 == 0) {
              zcl_packet_send(&input.data,0);
              goto _L0;
            }
          }
          else {
            if (10 < bVar5) {
              if (bVar5 == 0x44) {
                _offset_15 = (uint)offset_3 << 0x10;
                auStack_98 = (undefined1  [4])0x0;
                req.update_flags = '\0';
                req.action = '\0';
                req.direction = '\0';
                req._3_1_ = 0;
                req._4_4_ = (uint)req.start_hue << 0x10;
                af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,auStack_98);
                af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,auStack_98 + 1);
                af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,auStack_98 + 2);
                af_read_le16(*(zmsg_t **)((int)arg + 0x24),&offset_15,(uint16_t *)&req);
                af_read_le16(*(zmsg_t **)((int)arg + 0x24),&offset_15,(uint16_t *)&req.direction);
                uVar8 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
                uVar7 = 0x80;
                if ((_offset_15 & 0xffff) <= uVar8) {
                  af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,(uint8_t *)&req.time);
                  af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,
                              (uint8_t *)((int)&req.time + 1));
                  _Var3 = color_control_check_options_is_exec
                                    (*(uint8_t *)((int)arg + 0x15),(uint8_t)req.time,req.time._1_1_)
                  ;
                  if (CONCAT31(extraout_var_30,_Var3) == 0) goto _L0;
                  eVar4 = color_control_change_color_mode((zcl_packet_t *)arg,'\x03');
                  uVar7 = CONCAT31(extraout_var_31,eVar4);
                  if (uVar7 == 0) {
                    uVar14 = *(uint8_t *)((int)arg + 0x15);
                    input.end._0_2_ = 1;
                    input._20_4_ = cvc_enhanced_hue_output_handler;
                    input.cb = (zcl_cvc_output_callback_t)0x4000;
                    auStack_78[0] = uVar14;
                    input.ep_id = '\0';
                    input._1_3_ = 0;
                    input.begin = 0;
                    input.quant = 0;
                    input._14_2_ = 0;
                    input.duration._0_1_ = '\0';
                    pzVar6 = color_control_srv_get_attr_desc(uVar14,0x4002);
                    pzVar9 = color_control_srv_get_attr_desc(uVar14,0x4003);
                    pzVar10 = color_control_srv_get_attr_desc(uVar14,0x4004);
                    pzVar11 = color_control_srv_get_attr_desc(uVar14,0x4005);
                    pzVar12 = color_control_srv_get_attr_desc(uVar14,0x4000);
                    if ((((pzVar6 == (zcl_attr_desc_t *)0x0) || (pzVar9 == (zcl_attr_desc_t *)0x0))
                        || (pzVar10 == (zcl_attr_desc_t *)0x0)) ||
                       ((pzVar11 == (zcl_attr_desc_t *)0x0 || (pzVar12 == (zcl_attr_desc_t *)0x0))))
                    goto _L0;
                    if (((uint)auStack_98 & 2) != 0) {
                      *(byte *)pzVar9->data_p = auStack_98[2];
                    }
                    if (((uint)auStack_98 & 4) != 0) {
                      *(undefined2 *)pzVar10->data_p = req._0_2_;
                    }
                    if (((uint)auStack_98 & 8) != 0) {
                      *(undefined2 *)pzVar11->data_p = req._2_2_;
                    }
                    if (((uint)auStack_98 & 1) != 0) {
                      if (auStack_98[1] == '\x01') {
                        color_control_copy_attr_u16(uVar14,0x4000,0x4005);
                        *(undefined1 *)pzVar6->data_p = 1;
                      }
                      else if (auStack_98[1] == '\x02') {
                        color_control_copy_attr_u16(uVar14,0x4000,0x4006);
                        *(undefined1 *)pzVar6->data_p = 1;
                      }
                      else {
                        uVar7 = 0x87;
                        if (auStack_98[1] != '\0') goto _L0;
                    /* WARNING: Load size is inaccurate */
                        if (*pzVar6->data_p == '\x01') {
                          *(char *)pzVar6->data_p = '\0';
                          color_control_copy_attr_u16(uVar14,0x4006,0x4000);
                        }
                      }
                    }
                    /* WARNING: Load size is inaccurate */
                    if (*pzVar6->data_p != '\0') {
                    /* WARNING: Load size is inaccurate */
                      input._12_4_ = (uint)*pzVar10->data_p * 10;
                    /* WARNING: Load size is inaccurate */
                      input._0_4_ = ZEXT24(*pzVar12->data_p);
                    /* WARNING: Load size is inaccurate */
                      if (*pzVar9->data_p == '\0') {
                        iVar2 = 0x10000;
                      }
                      else {
                        iVar2 = -0x10000;
                      }
                      input.begin = input._0_4_ + iVar2;
                      schedule_cvc_color_line(uVar14,(zcl_cvc_input_t *)auStack_78);
                      goto _L0;
                    }
                    mode = '\x03';
_L0:
                    stop_cvc_color(uVar14,mode);
                    goto _L0;
                  }
                }
                goto _L0;
              }
              if (0x44 < bVar5) {
                if (bVar5 == 0x4b) {
                  _offset_15 = (uint)offset_3 << 0x10;
                  auStack_98 = (undefined1  [4])0x0;
                  req.update_flags = '\0';
                  req.action = '\0';
                  req.direction = '\0';
                  req._3_1_ = 0;
                  req._4_4_ = (uint)req.start_hue << 0x10;
                  af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,auStack_98);
                  af_read_le16(*(zmsg_t **)((int)arg + 0x24),&offset_15,(uint16_t *)(auStack_98 + 2)
                              );
                  af_read_le16(*(zmsg_t **)((int)arg + 0x24),&offset_15,(uint16_t *)&req);
                  af_read_le16(*(zmsg_t **)((int)arg + 0x24),&offset_15,(uint16_t *)&req.direction);
                  uVar8 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
                  uVar7 = 0x80;
                  if (uVar8 < (_offset_15 & 0xffff)) goto _L0;
                  af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,(uint8_t *)&req.time);
                  af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,
                              (uint8_t *)((int)&req.time + 1));
                  _Var3 = color_control_check_options_is_exec
                                    (*(uint8_t *)((int)arg + 0x15),(uint8_t)req.time,req.time._1_1_)
                  ;
                  if (CONCAT31(extraout_var_18,_Var3) == 0) goto _L0;
                  eVar4 = color_control_change_color_mode((zcl_packet_t *)arg,'\x02');
                  uVar7 = CONCAT31(extraout_var_19,eVar4);
                  if (uVar7 != 0) goto _L0;
                  uVar14 = *(uint8_t *)((int)arg + 0x15);
                  input.end._0_2_ = 1;
                  auStack_78[0] = uVar14;
                  input.ep_id = '\0';
                  input._1_3_ = 0;
                  input.begin = 0;
                  input.quant = 0;
                  input._14_2_ = 0;
                  input.duration._0_1_ = '\0';
                  input._20_4_ = cvc_color_temperature_output_handler;
                  input.cb = (zcl_cvc_output_callback_t)0x7;
                  pzVar6 = color_control_srv_get_attr_desc(uVar14,7);
                  if (pzVar6 == (zcl_attr_desc_t *)0x0) goto _L0;
                    /* WARNING: Load size is inaccurate */
                  input._0_4_ = ZEXT24(*pzVar6->data_p);
                  uVar7 = (uint)auStack_98 & 0xff;
                  if (uVar7 == 1) {
                    if (auStack_98._2_2_ != 0) {
                      pzVar6 = color_control_srv_get_attr_desc(uVar14,0x400c);
                      if (pzVar6 == (zcl_attr_desc_t *)0x0) goto _L0;
                      input.begin = (uint)req._0_4_ >> 0x10;
                      if (input.begin == 0) {
                    /* WARNING: Load size is inaccurate */
                        input.begin = (int32_t)*pzVar6->data_p;
                      }
                      if (input.begin <= (int)input._0_4_) {
_L0:
                        uVar7 = 0x87;
                        goto _L0;
                      }
                      iVar2 = ((uint)(ushort)input.end * 0xa0000 >> 0x10) *
                              (input.begin - input._0_4_);
_L0:
                      input._12_4_ = iVar2 / (int)((uint)auStack_98 >> 0x10);
                      iVar1 = input.begin;
                      goto _L0;
                    }
                  }
                  else if (uVar7 == 3) {
                    if (auStack_98._2_2_ != 0) {
                      pzVar6 = color_control_srv_get_attr_desc(uVar14,0x400b);
                      if (pzVar6 != (zcl_attr_desc_t *)0x0) {
                        input.begin = req._0_4_ & 0xffff;
                        if (input.begin == 0) {
                    /* WARNING: Load size is inaccurate */
                          input.begin = (int32_t)*pzVar6->data_p;
                        }
                        if ((int)input._0_4_ <= input.begin) goto _L0;
                        iVar2 = ((uint)(ushort)input.end * 0xa0000 >> 0x10) *
                                (input._0_4_ - input.begin);
                        goto _L0;
                      }
                      goto _L0;
                    }
                  }
                  else {
                    mode = '\x02';
                    if (uVar7 == 0) goto _L0;
                  }
                  goto _L0;
                }
                if (bVar5 != 0x4c) {
                  if (bVar5 != 0x47) {
_L0:
                    uVar7 = 0x81;
                    goto _L0;
                  }
                  auStack_78._0_2_ = 0;
                  auStack_98 = (undefined1  [4])((uint)auStack_98 & 0xffff0000);
                  af_read_le8(*(zmsg_t **)((int)arg + 0x24),(uint16_t *)auStack_78,auStack_98);
                  af_read_le8(*(zmsg_t **)((int)arg + 0x24),(uint16_t *)auStack_78,auStack_98 + 1);
                  _Var3 = color_control_check_options_is_exec
                                    (*(uint8_t *)((int)arg + 0x15),auStack_98[0],auStack_98[1]);
                  if (CONCAT31(extraout_var_04,_Var3) != 0) {
                    uVar14 = *(uint8_t *)((int)arg + 0x15);
                    mode = 0xff;
                    goto _L0;
                  }
_L0:
                  uVar7 = 0;
                  goto _L0;
                }
                _offset_15 = (uint)offset_3 << 0x10;
                auStack_98 = (undefined1  [4])0x0;
                req.update_flags = '\0';
                req.action = '\0';
                req.direction = '\0';
                req._3_1_ = 0;
                req.time = 0;
                req.start_hue = 0;
                af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,auStack_98);
                af_read_le16(*(zmsg_t **)((int)arg + 0x24),&offset_15,(uint16_t *)(auStack_98 + 2));
                af_read_le16(*(zmsg_t **)((int)arg + 0x24),&offset_15,&req.time);
                af_read_le16(*(zmsg_t **)((int)arg + 0x24),&offset_15,(uint16_t *)&req);
                af_read_le16(*(zmsg_t **)((int)arg + 0x24),&offset_15,(uint16_t *)&req.direction);
                uVar8 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
                if (uVar8 < (_offset_15 & 0xffff)) goto _L0;
                af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,(uint8_t *)&req.start_hue);
                af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,
                            (uint8_t *)((int)&req.start_hue + 1));
                _Var3 = color_control_check_options_is_exec
                                  (*(uint8_t *)((int)arg + 0x15),(uint8_t)req.start_hue,
                                   req.start_hue._1_1_);
                if (CONCAT31(extraout_var_20,_Var3) != 0) {
                  eVar4 = color_control_change_color_mode((zcl_packet_t *)arg,'\x02');
                  uVar7 = CONCAT31(extraout_var_21,eVar4);
                  if (uVar7 == 0) {
                    input._12_4_ = req._4_4_ & 0xffff;
                    uVar14 = *(uint8_t *)((int)arg + 0x15);
                    auStack_78[0] = uVar14;
                    input.ep_id = '\0';
                    input._1_3_ = 0;
                    input.begin = 0;
                    input.end._0_2_ = 1;
                    input.duration._0_1_ = '\0';
                    input._20_4_ = cvc_color_temperature_output_handler;
                    input.cb = (zcl_cvc_output_callback_t)0x7;
                    pzVar6 = color_control_srv_get_attr_desc(uVar14,7);
                    if (pzVar6 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
                      input._0_4_ = ZEXT24(*pzVar6->data_p);
                      if (((uint)auStack_98 & 0xff) == 1) {
                        pzVar6 = color_control_srv_get_attr_desc(uVar14,0x400c);
                        if (pzVar6 != (zcl_attr_desc_t *)0x0) {
                          uVar7 = (uint)req._0_4_ >> 0x10;
                          if (uVar7 == 0) {
                    /* WARNING: Load size is inaccurate */
                            uVar7 = (uint)*pzVar6->data_p;
                          }
                          input.begin = ((uint)auStack_98 >> 0x10) + input._0_4_;
                          if ((int)uVar7 < input.begin) {
_L0:
                            input.begin = uVar7;
                          }
_L0:
                          iVar2 = 0;
                          goto _L0;
                        }
                      }
                      else {
                        if (((uint)auStack_98 & 0xff) != 3) {
                          iVar2 = 0x85;
_L0:
                          remaining_time = req.time;
                          goto _L0;
                        }
                        pzVar6 = color_control_srv_get_attr_desc(uVar14,0x400b);
                        if (pzVar6 != (zcl_attr_desc_t *)0x0) {
                          uVar7 = req._0_4_ & 0xffff;
                          if (uVar7 == 0) {
                    /* WARNING: Load size is inaccurate */
                            uVar7 = (uint)*pzVar6->data_p;
                          }
                          input.begin = input._0_4_ - ((uint)auStack_98 >> 0x10);
                          if (input.begin < (int)uVar7) goto _L0;
                          goto _L0;
                        }
                      }
                    }
                    goto _L0;
                  }
                }
                goto _L0;
              }
              if (bVar5 == 0x42) {
                _offset_15 = (uint)offset_3 << 0x10;
                auStack_98 = (undefined1  [4])0x0;
                req.update_flags = '\0';
                req.action = '\0';
                req.direction = '\0';
                req._3_1_ = 0;
                af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,auStack_98);
                af_read_le16(*(zmsg_t **)((int)arg + 0x24),&offset_15,(uint16_t *)(auStack_98 + 2));
                af_read_le16(*(zmsg_t **)((int)arg + 0x24),&offset_15,(uint16_t *)&req);
                af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,&req.direction);
                af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,&req.field_0x3);
                _Var3 = color_control_check_options_is_exec
                                  (*(uint8_t *)((int)arg + 0x15),req.direction,req._3_1_);
                if (CONCAT31(extraout_var_26,_Var3) != 0) {
                  eVar4 = color_control_change_color_mode((zcl_packet_t *)arg,'\x03');
                  uVar7 = CONCAT31(extraout_var_27,eVar4);
                  if (uVar7 == 0) {
                    input._12_4_ = req._0_4_ & 0xffff;
                    uVar14 = *(uint8_t *)((int)arg + 0x15);
                    auStack_78[0] = uVar14;
                    input.ep_id = '\0';
                    input._1_3_ = 0;
                    input.begin = 0;
                    input.end._0_2_ = 1;
                    input.duration._0_1_ = '\0';
                    input._20_4_ = cvc_enhanced_hue_output_handler;
                    input.cb = (zcl_cvc_output_callback_t)0x4000;
                    pzVar6 = color_control_srv_get_attr_desc(uVar14,0x4000);
                    if (pzVar6 == (zcl_attr_desc_t *)0x0) goto _L0;
                    /* WARNING: Load size is inaccurate */
                    input._0_4_ = ZEXT24(*pzVar6->data_p);
                    if (((uint)auStack_98 & 0xff) == 1) {
                      uVar7 = (uint)(ushort)auStack_98._2_2_;
_L0:
                      input.begin = input._0_4_ + uVar7;
                      iVar2 = 0;
                    }
                    else {
                      if (((uint)auStack_98 & 0xff) == 3) {
                        uVar7 = -(uint)(ushort)auStack_98._2_2_;
                        goto _L0;
                      }
                      iVar2 = 0x85;
                    }
                    remaining_time = req._0_2_;
_L0:
                    color_control_set_remaining_time(uVar14,remaining_time);
                    if (iVar2 == 0) goto _L0;
_L0:
                    uVar7 = 0x85;
                  }
                }
              }
              else {
                if (bVar5 == 0x43) {
                  uStack_a2 = 0;
                  _offset_15 = 0;
                  _offset = 0;
                  af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,&offset_15);
                  af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,(uint8_t *)&offset_3);
                  af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,&offset);
                  uVar8 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
                  if (uVar8 < uStack_a2) goto _L0;
                  af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,(uint8_t *)&uStack_9a);
                  af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,
                              (uint8_t *)((int)&uStack_9a + 1));
                  _Var3 = color_control_check_options_is_exec
                                    (*(uint8_t *)((int)arg + 0x15),(uint8_t)uStack_9a,
                                     uStack_9a._1_1_);
                  if (CONCAT31(extraout_var_28,_Var3) != 0) {
                    eVar4 = color_control_change_color_mode((zcl_packet_t *)arg,'\x03');
                    uVar7 = CONCAT31(extraout_var_29,eVar4);
                    if (uVar7 == 0) {
                      uVar14 = *(uint8_t *)((int)arg + 0x15);
                      memset(auStack_98,0,0x18);
                      uVar7 = _offset & 0xffff;
                      auStack_98[0] = uVar14;
                      req.options_mask = '\x01';
                      req.options_override = '\0';
                      memset(auStack_78,0,0x18);
                      input._20_4_ = cvc_sat_output_handler;
                      auStack_78[0] = uVar14;
                      input.end._0_2_ = 1;
                      input.cb = (zcl_cvc_output_callback_t)0x1;
                      input._12_4_ = uVar7;
                      if ((char)offset_3 == -1) goto _L0;
                      pzVar6 = color_control_srv_get_attr_desc(uVar14,0x4000);
                      pzVar9 = color_control_srv_get_attr_desc(uVar14,1);
                      if ((pzVar6 != (zcl_attr_desc_t *)0x0) && (pzVar9 != (zcl_attr_desc_t *)0x0))
                      {
                    /* WARNING: Load size is inaccurate */
                        uVar13 = *pzVar6->data_p;
                    /* WARNING: Load size is inaccurate */
                        input._0_4_ = ZEXT14(*pzVar9->data_p);
                        input.begin = _offset_15 >> 0x10 & 0xff;
                        goto _L0;
                      }
                      goto _L0;
                    }
                  }
                  goto _L0;
                }
                if (bVar5 != 0x40) {
                  if (bVar5 != 0x41) goto _L0;
                  _offset_15 = (uint)offset_3 << 0x10;
                  auStack_98 = (undefined1  [4])0x0;
                  req._0_4_ = (uint)(ushort)req._2_2_ << 0x10;
                  af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,auStack_98);
                  af_read_le16(*(zmsg_t **)((int)arg + 0x24),&offset_15,(uint16_t *)(auStack_98 + 2)
                              );
                  uVar8 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
                  uVar7 = 0x80;
                  if (uVar8 < (_offset_15 & 0xffff)) goto _L0;
                  af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,&req.update_flags);
                  af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,&req.action);
                  _Var3 = color_control_check_options_is_exec
                                    (*(uint8_t *)((int)arg + 0x15),req.update_flags,req.action);
                  if (CONCAT31(extraout_var_24,_Var3) == 0) goto _L0;
                  eVar4 = color_control_change_color_mode((zcl_packet_t *)arg,'\x03');
                  uVar7 = CONCAT31(extraout_var_25,eVar4);
                  if (uVar7 != 0) goto _L0;
                  uVar14 = *(uint8_t *)((int)arg + 0x15);
                  input.quant = 10;
                  input._14_2_ = 0;
                  auStack_78[0] = uVar14;
                  input.ep_id = '\0';
                  input._1_3_ = 0;
                  input.begin = 0;
                  input.end._0_2_ = 1;
                  input.duration._0_1_ = '\x01';
                  input._20_4_ = cvc_enhanced_hue_output_handler;
                  input.cb = (zcl_cvc_output_callback_t)0x4000;
                  pzVar6 = color_control_srv_get_attr_desc(uVar14,0x4000);
                  if (pzVar6 == (zcl_attr_desc_t *)0x0) goto _L0;
                  uVar7 = (uint)auStack_98 & 0xff;
                    /* WARNING: Load size is inaccurate */
                  input._0_4_ = ZEXT24(*pzVar6->data_p);
                  if (uVar7 == 1) {
                    uVar7 = (uint)(ushort)auStack_98._2_2_;
                    goto _L0;
                  }
                  mode = '\x03';
                  if (uVar7 != 3) {
                    if (uVar7 != 0) goto _L0;
                    goto _L0;
                  }
                  uVar7 = (uint)(ushort)auStack_98._2_2_;
_L0:
                  if (uVar7 != 0) {
                    iVar1 = input._0_4_ - uVar7;
                    goto _L0;
                  }
                  goto _L0;
                }
                _offset_15 = (uint)offset_3 << 0x10;
                auStack_98 = (undefined1  [4])0x0;
                req.update_flags = '\0';
                req.action = '\0';
                req.direction = '\0';
                req._3_1_ = 0;
                af_read_le16(*(zmsg_t **)((int)arg + 0x24),&offset_15,(uint16_t *)auStack_98);
                af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,auStack_98 + 2);
                af_read_le16(*(zmsg_t **)((int)arg + 0x24),&offset_15,(uint16_t *)&req);
                uVar8 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
                if (uVar8 < (_offset_15 & 0xffff)) goto _L0;
                af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,&req.direction);
                af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,&req.field_0x3);
                _Var3 = color_control_check_options_is_exec
                                  (*(uint8_t *)((int)arg + 0x15),req.direction,req._3_1_);
                if (CONCAT31(extraout_var_22,_Var3) != 0) {
                  eVar4 = color_control_change_color_mode((zcl_packet_t *)arg,'\x03');
                  uVar7 = CONCAT31(extraout_var_23,eVar4);
                  if (uVar7 == 0) {
                    uVar14 = *(uint8_t *)((int)arg + 0x15);
                    memset(auStack_78,0,0x18);
                    input.end._0_2_ = 1;
                    input._12_4_ = req._0_4_ & 0xffff;
                    auStack_78[0] = uVar14;
                    input._20_4_ = cvc_enhanced_hue_output_handler;
                    input.cb = (zcl_cvc_output_callback_t)0x4000;
                    pzVar6 = color_control_srv_get_attr_desc(uVar14,0x4000);
                    if (pzVar6 == (zcl_attr_desc_t *)0x0) goto _L0;
                    /* WARNING: Load size is inaccurate */
                    input._0_4_ = ZEXT24(*pzVar6->data_p);
                    uVar7 = (uint)auStack_98 & 0xffff;
                    if (auStack_98[2] == 2) {
_L0:
                      input.begin = uVar7;
                      if ((uint)input._0_4_ <= uVar7) goto _L0;
                      iVar2 = 0x10000;
_L0:
                      input.begin = uVar7 + iVar2;
                      goto _L0;
                    }
                    if (auStack_98[2] < 3) {
                      if (auStack_98[2] == 0) {
                        iVar2 = input._0_4_ - uVar7;
                        if ((uint)input._0_4_ <= uVar7) {
                          iVar2 = uVar7 - input._0_4_;
                        }
                      }
                      else {
                        iVar2 = input._0_4_ - uVar7;
                        if ((uint)input._0_4_ <= uVar7) {
                          iVar2 = uVar7 - input._0_4_;
                        }
                      }
                      if ((uint)input._0_4_ < uVar7 == 0x8000 < iVar2) goto _L0;
_L0:
                      input.begin = uVar7;
                      if (uVar7 <= (uint)input._0_4_) goto _L0;
                      iVar2 = -0x10000;
                      goto _L0;
                    }
                    if (auStack_98[2] == 3) goto _L0;
                    goto _L0;
                  }
                }
              }
              goto _L0;
            }
            payload = *(zmsg_t **)((int)arg + 0x24);
            if (bVar5 == 6) {
              uStack_a2 = 0;
              _offset_15 = 0;
              _offset = (uint)uStack_9a << 0x10;
              af_read_le8(payload,&uStack_a2,(uint8_t *)&offset_15);
              af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,(uint8_t *)((int)&offset_15 + 1))
              ;
              af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,&offset_3);
              uVar8 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
              if (uVar8 < uStack_a2) goto _L0;
              af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,(uint8_t *)&offset);
              af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,(uint8_t *)((int)&offset + 1));
              _Var3 = color_control_check_options_is_exec
                                (*(uint8_t *)((int)arg + 0x15),(uint8_t)offset,offset._1_1_);
              if (CONCAT31(extraout_var_10,_Var3) != 0) {
                eVar4 = color_control_change_color_mode((zcl_packet_t *)arg,'\0');
                uVar7 = CONCAT31(extraout_var_11,eVar4);
                if (uVar7 == 0) {
                  uVar14 = *(uint8_t *)((int)arg + 0x15);
                  memset(auStack_98,0,0x20);
                  uVar7 = _offset_15 >> 0x10;
                  auStack_98[0] = uVar14;
                  req.options_mask = '\x01';
                  req.options_override = '\0';
                  memset(auStack_78,0,0x18);
                  input._20_4_ = cvc_sat_output_handler;
                  auStack_78[0] = uVar14;
                  input.end._0_2_ = 1;
                  input.cb = (zcl_cvc_output_callback_t)0x1;
                  input._12_4_ = uVar7;
                  if ((offset_15._1_1_ != -1) && ((char)offset_15 != -1)) {
                    pzVar6 = color_control_srv_get_attr_desc(uVar14,0);
                    pzVar9 = color_control_srv_get_attr_desc(uVar14,1);
                    if ((pzVar6 != (zcl_attr_desc_t *)0x0) && (pzVar9 != (zcl_attr_desc_t *)0x0)) {
                    /* WARNING: Load size is inaccurate */
                      req._0_4_ = ZEXT14(*pzVar6->data_p);
                      req._4_4_ = _offset_15 & 0xff;
                    /* WARNING: Load size is inaccurate */
                      input._0_4_ = ZEXT14(*pzVar9->data_p);
                      input.begin = _offset_15 >> 8 & 0xff;
                      goto _L0;
                    }
                    goto _L0;
                  }
_L0:
                  input.end._0_2_ = 1;
                  uVar7 = 0x87;
                }
              }
              goto _L0;
            }
            if (bVar5 < 7) {
              if (bVar5 == 3) {
                _offset_15 = (uint)offset_3 << 0x10;
                auStack_98 = (undefined1  [4])0x0;
                req._0_4_ = (uint)(ushort)req._2_2_ << 0x10;
                af_read_le8(payload,&offset_15,auStack_98);
                af_read_le16(*(zmsg_t **)((int)arg + 0x24),&offset_15,(uint16_t *)(auStack_98 + 2));
                uVar8 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
                if (uVar8 < (_offset_15 & 0xffff)) goto _L0;
                af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,&req.update_flags);
                af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,&req.action);
                _Var3 = color_control_check_options_is_exec
                                  (*(uint8_t *)((int)arg + 0x15),req.update_flags,req.action);
                if (CONCAT31(extraout_var_08,_Var3) != 0) {
                  eVar4 = color_control_change_color_mode((zcl_packet_t *)arg,'\0');
                  uVar7 = CONCAT31(extraout_var_09,eVar4);
                  if (uVar7 == 0) {
                    uVar14 = *(uint8_t *)((int)arg + 0x15);
                    memset(auStack_78,0,0x18);
                    input._12_4_ = (uint)auStack_98 >> 0x10;
                    input.end._0_2_ = 1;
                    input.cb = (zcl_cvc_output_callback_t)0x1;
                    input._20_4_ = cvc_sat_output_handler;
                    auStack_78[0] = uVar14;
                    if (auStack_98[0] == 0xff) goto _L0;
                    pzVar6 = color_control_srv_get_attr_desc(uVar14,1);
                    if (pzVar6 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
                      input._0_4_ = ZEXT14(*pzVar6->data_p);
                      input.begin = (uint)auStack_98 & 0xff;
                      goto _L0;
                    }
                    goto _L0;
                  }
                }
              }
              else if (bVar5 < 4) {
                if (bVar5 == 1) {
_L0:
                  _offset_15 = (uint)offset_3 << 0x10;
                  auStack_98 = (undefined1  [4])0x0;
                  af_read_le8(payload,&offset_15,auStack_98);
                  af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,auStack_98 + 1);
                  uVar8 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
                  uVar7 = 0x80;
                  if ((_offset_15 & 0xffff) <= uVar8) {
                    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,auStack_98 + 2);
                    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,auStack_98 + 3);
                    _Var3 = color_control_check_options_is_exec
                                      (*(uint8_t *)((int)arg + 0x15),auStack_98[2],auStack_98[3]);
                    if (CONCAT31(extraout_var_01,_Var3) == 0) goto _L0;
                    eVar4 = color_control_change_color_mode((zcl_packet_t *)arg,'\0');
                    uVar7 = CONCAT31(extraout_var_07,eVar4);
                    if (uVar7 == 0) {
                      uVar14 = *(uint8_t *)((int)arg + 0x15);
                      input.duration._0_1_ = *(char *)((int)arg + 0x20);
                      auStack_78[0] = uVar14;
                      input.ep_id = '\0';
                      input._1_3_ = 0;
                      input.begin = 0;
                      if ((char)input.duration == '\x01') {
                        input.quant = 10;
                        input._14_2_ = 0;
                        input.end._0_2_ = 1;
                        input._20_4_ = cvc_hue_output_handler;
                        input.cb = (zcl_cvc_output_callback_t)0x0;
                        pzVar6 = color_control_srv_get_attr_desc(uVar14,0);
                        if (pzVar6 != (zcl_attr_desc_t *)0x0) {
                          uVar7 = (uint)auStack_98 & 0xff;
                    /* WARNING: Load size is inaccurate */
                          input._0_4_ = ZEXT14(*pzVar6->data_p);
                          if (uVar7 == 1) {
                            uVar7 = (uint)auStack_98[1];
_L0:
                            iVar1 = input._0_4_ + uVar7;
                            if (uVar7 != 0) goto _L0;
                          }
                          else {
                            if (uVar7 == 3) {
                              uVar7 = (uint)auStack_98[1];
                              goto _L0;
                            }
joined_r0x0001278c:
                            if (uVar7 == 0) {
                              mode = '\0';
                              goto _L0;
                            }
                          }
                          goto _L0;
                        }
                      }
                      else {
                        input.end._0_2_ = 1;
                        input.quant = 0;
                        input._14_2_ = 0;
                        input.duration._0_1_ = '\0';
                        input._20_4_ = cvc_sat_output_handler;
                        input.cb = (zcl_cvc_output_callback_t)0x1;
                        pzVar6 = color_control_srv_get_attr_desc(uVar14,1);
                        if (pzVar6 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
                          input._0_4_ = ZEXT14(*pzVar6->data_p);
                          uVar7 = (uint)auStack_98 & 0xff;
                          if (uVar7 == 1) {
                            if (auStack_98[1] != 0) {
                              input._12_4_ = (int)(((uint)(ushort)input.end * 0xa0000 >> 0x10) *
                                                  (0xfe - input._0_4_)) / (int)(uint)auStack_98[1];
                              iVar1 = 0xfe;
_L0:
                              input.begin = iVar1;
                              bVar5 = schedule_cvc_color_line(uVar14,(zcl_cvc_input_t *)auStack_78);
                              uVar7 = (uint)bVar5;
                              goto _L0;
                            }
                          }
                          else {
                            if (uVar7 != 3) goto joined_r0x0001278c;
                            if (auStack_98[1] != 0) {
                              input._12_4_ = (((uint)(ushort)input.end * 0xa0000 >> 0x10) *
                                             input._0_4_) / (uint)auStack_98[1];
                              iVar1 = 0;
                              goto _L0;
                            }
                          }
_L0:
                          uVar7 = 0x85;
                          goto _L0;
                        }
                      }
_L0:
                      uVar7 = 0x86;
                    }
                  }
                }
                else {
                  if (bVar5 == 2) goto _L0;
                  _offset_15 = (uint)offset_3 << 0x10;
                  auStack_98 = (undefined1  [4])0x0;
                  req._0_4_ = (uint)(ushort)req._2_2_ << 0x10;
                  af_read_le8(payload,&offset_15,auStack_98);
                  af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,auStack_98 + 1);
                  af_read_le16(*(zmsg_t **)((int)arg + 0x24),&offset_15,(uint16_t *)(auStack_98 + 2)
                              );
                  uVar8 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
                  if (uVar8 < (_offset_15 & 0xffff)) goto _L0;
                  af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,&req.update_flags);
                  af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,&req.action);
                  _Var3 = color_control_check_options_is_exec
                                    (*(uint8_t *)((int)arg + 0x15),req.update_flags,req.action);
                  if (CONCAT31(extraout_var_05,_Var3) != 0) {
                    eVar4 = color_control_change_color_mode((zcl_packet_t *)arg,'\0');
                    uVar7 = CONCAT31(extraout_var_06,eVar4);
                    if (uVar7 == 0) {
                      uVar14 = *(uint8_t *)((int)arg + 0x15);
                      memset(auStack_78,0,0x20);
                      input.end._0_2_ = 1;
                      input._12_4_ = (uint)auStack_98 >> 0x10;
                      auStack_78[0] = uVar14;
                      input._20_4_ = cvc_hue_output_handler;
                      if (auStack_98[0] == 0xff) goto _L0;
                      pzVar6 = color_control_srv_get_attr_desc(uVar14,0);
                      if (pzVar6 == (zcl_attr_desc_t *)0x0) goto _L0;
                    /* WARNING: Load size is inaccurate */
                      input._0_4_ = ZEXT14(*pzVar6->data_p);
                      uVar7 = (uint)auStack_98 & 0xff;
                      if (auStack_98[1] == 2) goto _L0;
                      if (auStack_98[1] < 3) {
                        if (auStack_98[1] == 0) {
                          iVar2 = input._0_4_ - uVar7;
                          if ((uint)input._0_4_ <= uVar7) {
                            iVar2 = uVar7 - input._0_4_;
                          }
                          if ((uint)input._0_4_ < uVar7 == 0x7f < iVar2) goto _L0;
                        }
                        else {
                          iVar2 = input._0_4_ - uVar7;
                          if ((uint)input._0_4_ <= uVar7) {
                            iVar2 = uVar7 - input._0_4_;
                          }
                          if ((uint)input._0_4_ < uVar7 != 0x7f < iVar2) goto _L0;
                        }
_L0:
                        input.begin = uVar7;
                        if (uVar7 < (uint)input._0_4_) {
                          input.begin = uVar7 + 0xff;
                        }
                      }
                      else {
                        if (auStack_98[1] != 3) goto _L0;
_L0:
                        input.begin = uVar7;
                        if ((uint)input._0_4_ < uVar7) {
                          input.begin = uVar7 - 0xff;
                        }
                      }
                      goto _L0;
                    }
                  }
                }
              }
              else {
                if (bVar5 == 4) goto _L0;
_L0:
                _offset_15 = (uint)offset_3 << 0x10;
                auStack_98 = (undefined1  [4])0x0;
                req._0_4_ = req._0_4_ & 0xffff0000;
                af_read_le8(payload,&offset_15,auStack_98);
                af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,auStack_98 + 1);
                af_read_le16(*(zmsg_t **)((int)arg + 0x24),&offset_15,(uint16_t *)(auStack_98 + 2));
                uVar8 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
                if (uVar8 < (_offset_15 & 0xffff)) goto _L0;
                af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,&req.update_flags);
                af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset_15,&req.action);
                _Var3 = color_control_check_options_is_exec
                                  (*(uint8_t *)((int)arg + 0x15),req.update_flags,req.action);
                if (CONCAT31(extraout_var,_Var3) != 0) {
                  eVar4 = color_control_change_color_mode((zcl_packet_t *)arg,'\0');
                  uVar7 = CONCAT31(extraout_var_00,eVar4);
                  if (uVar7 == 0) {
                    uVar14 = *(uint8_t *)((int)arg + 0x15);
                    input._12_4_ = (uint)auStack_98 >> 0x10;
                    auStack_78[0] = uVar14;
                    input.ep_id = '\0';
                    input._1_3_ = 0;
                    input.begin = 0;
                    input.end._0_2_ = 1;
                    input.duration._0_1_ = '\0';
                    if (*(char *)((int)arg + 0x20) != '\x02') {
                      input._20_4_ = cvc_sat_output_handler;
                      input.cb = (zcl_cvc_output_callback_t)0x1;
                      pzVar6 = color_control_srv_get_attr_desc(uVar14,1);
                      if (pzVar6 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
                        input._0_4_ = ZEXT14(*pzVar6->data_p);
                        if (((uint)auStack_98 & 0xff) == 1) {
                          input.begin = input._0_4_ + (uint)auStack_98[1];
                          if (0xfe < input._0_4_ + (uint)auStack_98[1]) {
                            input.begin = 0xfe;
                          }
                        }
                        else {
                          if (((uint)auStack_98 & 0xff) != 3) goto _L0;
                          input.begin = input._0_4_ - (uint)auStack_98[1] &
                                        (int)~(input._0_4_ - (uint)auStack_98[1]) >> 0x1f;
                        }
                        goto _L0;
                      }
_L0:
                      uVar7 = 0x86;
                      goto _L0;
                    }
                    input._20_4_ = cvc_hue_output_handler;
                    input.cb = (zcl_cvc_output_callback_t)0x0;
                    pzVar6 = color_control_srv_get_attr_desc(uVar14,0);
                    if (pzVar6 == (zcl_attr_desc_t *)0x0) goto _L0;
                    /* WARNING: Load size is inaccurate */
                    input._0_4_ = ZEXT14(*pzVar6->data_p);
                    if (((uint)auStack_98 & 0xff) == 1) {
                      input.begin = input._0_4_ + (uint)auStack_98[1];
_L0:
                      iVar2 = 0;
                    }
                    else {
                      if (((uint)auStack_98 & 0xff) == 3) {
                        input.begin = input._0_4_ - (uint)auStack_98[1];
                        goto _L0;
                      }
_L0:
                      iVar2 = 0x85;
                    }
                    remaining_time = auStack_98._2_2_;
                    goto _L0;
                  }
                }
              }
              goto _L0;
            }
            if (bVar5 == 8) {
              uStack_a2 = 0;
              _offset_15 = 0;
              _offset = (uint)uStack_9a << 0x10;
              af_read_le16(payload,&uStack_a2,&offset_15);
              af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,&offset_3);
              uVar8 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
              if (uVar8 < uStack_a2) goto _L0;
              af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,(uint8_t *)&offset);
              af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,(uint8_t *)((int)&offset + 1));
              _Var3 = color_control_check_options_is_exec
                                (*(uint8_t *)((int)arg + 0x15),(uint8_t)offset,offset._1_1_);
              if (CONCAT31(extraout_var_14,_Var3) != 0) {
                eVar4 = color_control_change_color_mode((zcl_packet_t *)arg,'\x01');
                uVar7 = CONCAT31(extraout_var_15,eVar4);
                if (uVar7 == 0) {
                  input._20_4_ = cvc_color_xy_output_handler;
                  uVar14 = *(uint8_t *)((int)arg + 0x15);
                  req.options_mask = '\x01';
                  req.options_override = '\0';
                  input.end._0_2_ = 1;
                  input.duration._0_1_ = '\x01';
                  input.cb = (zcl_cvc_output_callback_t)0x4;
                  auStack_98[0] = uVar14;
                  req.update_flags = '\0';
                  req.action = '\0';
                  req.direction = '\0';
                  req._3_1_ = 0;
                  req.time = 0;
                  req.start_hue = 0;
                  auStack_78[0] = uVar14;
                  input.ep_id = '\0';
                  input._1_3_ = 0;
                  input.begin = 0;
                  input.quant = 0;
                  input._14_2_ = 0;
                  if (offset_15 != 0 || offset_3 != 0) {
                    pzVar6 = color_control_srv_get_attr_desc(uVar14,3);
                    pzVar9 = color_control_srv_get_attr_desc(uVar14,4);
                    if ((pzVar6 != (zcl_attr_desc_t *)0x0) && (pzVar9 != (zcl_attr_desc_t *)0x0)) {
                    /* WARNING: Load size is inaccurate */
                      req._0_4_ = ZEXT24(*pzVar6->data_p);
                    /* WARNING: Load size is inaccurate */
                      input._0_4_ = ZEXT24(*pzVar9->data_p);
                      req._4_4_ = req._0_4_ + (_offset_15 & 0xffff);
                      input.begin = input._0_4_ + (_offset_15 >> 0x10);
                      input._12_4_ = (-(uint)(_offset_15 >> 0x10 == 0) & 0xfffffff6) + 10;
                      goto _L0;
                    }
                    goto _L0;
                  }
                  stop_cvc_color(uVar14,'\x01');
                  uVar7 = 0xfe;
                }
              }
              goto _L0;
            }
            if (bVar5 == 9) {
              uStack_a2 = 0;
              _offset_15 = 0;
              _offset = _offset & 0xffff0000;
              af_read_le16(payload,&uStack_a2,&offset_15);
              af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,
                           (uint16_t *)((int)&offset_15 + 1));
              af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,&offset_3);
              uVar8 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
              if (uVar8 < uStack_a2) goto _L0;
              af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,(uint8_t *)&offset);
              af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,(uint8_t *)((int)&offset + 1));
              _Var3 = color_control_check_options_is_exec
                                (*(uint8_t *)((int)arg + 0x15),(uint8_t)offset,offset._1_1_);
              if (CONCAT31(extraout_var_02,_Var3) != 0) {
                eVar4 = color_control_change_color_mode((zcl_packet_t *)arg,'\x01');
                uVar7 = CONCAT31(extraout_var_03,eVar4);
                if (uVar7 == 0) {
                  uVar14 = *(uint8_t *)((int)arg + 0x15);
                  input._12_4_ = _offset_15 >> 0x10;
                  auStack_98[0] = uVar14;
                  req.update_flags = '\0';
                  req.action = '\0';
                  req.direction = '\0';
                  req._3_1_ = 0;
                  req.time = 0;
                  req.start_hue = 0;
                  req.options_mask = '\x01';
                  req.options_override = '\0';
                  auStack_78[0] = uVar14;
                  input.ep_id = '\0';
                  input._1_3_ = 0;
                  input.begin = 0;
                  input.end._0_2_ = 1;
                  input.duration._0_1_ = '\0';
                  input._20_4_ = cvc_color_xy_output_handler;
                  input.cb = (zcl_cvc_output_callback_t)0x4;
                  pzVar6 = color_control_srv_get_attr_desc(uVar14,3);
                  pzVar9 = color_control_srv_get_attr_desc(uVar14,4);
                  if ((pzVar6 == (zcl_attr_desc_t *)0x0) || (pzVar9 == (zcl_attr_desc_t *)0x0))
                  goto _L0;
                    /* WARNING: Load size is inaccurate */
                  req._0_4_ = ZEXT24(*pzVar6->data_p);
                    /* WARNING: Load size is inaccurate */
                  input._0_4_ = ZEXT24(*pzVar9->data_p);
                  req._4_4_ = (_offset_15 & 0xff) + req._0_4_;
                  input.begin = (_offset_15 >> 8 & 0xff) + input._0_4_;
                  color_control_set_remaining_time(uVar14,offset_3);
_L0:
                  bVar5 = schedule_cvc_color_space
                                    (uVar14,(zcl_cvc_input_t *)auStack_98,
                                     (zcl_cvc_input_t *)auStack_78);
                  goto _L0;
                }
              }
              goto _L0;
            }
            uStack_a2 = 0;
            _offset_15 = 0;
            _offset = 0;
            af_read_le16(payload,&uStack_a2,&offset_15);
            af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,&offset_3);
            af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,&offset);
            uVar8 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
            if (uVar8 < uStack_a2) {
_L0:
              uVar7 = 0x80;
              goto _L0;
            }
            af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,(uint8_t *)&uStack_9a);
            af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,(uint8_t *)((int)&uStack_9a + 1));
            _Var3 = color_control_check_options_is_exec
                              (*(uint8_t *)((int)arg + 0x15),(uint8_t)uStack_9a,uStack_9a._1_1_);
            if (CONCAT31(extraout_var_12,_Var3) == 0) goto _L0;
            eVar4 = color_control_change_color_mode((zcl_packet_t *)arg,'\x01');
            uVar7 = CONCAT31(extraout_var_13,eVar4);
            if (uVar7 == 0) {
              uVar14 = *(uint8_t *)((int)arg + 0x15);
              memset(auStack_98,0,0x18);
              uVar7 = _offset & 0xffff;
              auStack_98[0] = uVar14;
              req.options_mask = '\x01';
              req.options_override = '\0';
              memset(auStack_78,0,0x18);
              auStack_78[0] = uVar14;
              input.end._0_2_ = 1;
              input._20_4_ = cvc_color_xy_output_handler;
              input.cb = (zcl_cvc_output_callback_t)0x4;
              input._12_4_ = uVar7;
              if ((0xfeff < offset_15) || (0xfeff < offset_3)) goto _L0;
              pzVar6 = color_control_srv_get_attr_desc(uVar14,3);
              pzVar9 = color_control_srv_get_attr_desc(uVar14,4);
              if ((pzVar6 != (zcl_attr_desc_t *)0x0) && (pzVar9 != (zcl_attr_desc_t *)0x0)) {
                    /* WARNING: Load size is inaccurate */
                uVar13 = *pzVar6->data_p;
                    /* WARNING: Load size is inaccurate */
                input._0_4_ = ZEXT24(*pzVar9->data_p);
                input.begin = _offset_15 >> 0x10;
_L0:
                req._4_4_ = _offset_15 & 0xffff;
                req._2_2_ = 0;
                req.update_flags = (char)uVar13;
                req.action = (char)(uVar13 >> 8);
                goto _L0;
              }
              goto _L0;
            }
            if (uVar7 != 0xfe) goto _L0;
          }
          zcl_packet_free(&input.data);
          goto _L0;
        }
      }
      else {
        if (bVar5 == 0x47) goto _L0;
        if (bVar5 < 0x48) {
          uVar13 = uVar13 >> 2;
          if (bVar5 == 0x44) goto _L0;
        }
        else if ((byte)(bVar5 + 0xb5) < 2) goto _L0;
      }
    }
  }
_L0:
  uVar7 = 1;
_L0:
  return (ezb_zcl_status_t)uVar7;
}

