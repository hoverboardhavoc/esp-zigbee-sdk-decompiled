/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> level.o -> level_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: rsp */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t level_cluster_srv_cmd_proc_handler(void *arg)

{
  byte cmd_id;
  char cVar1;
  int iVar2;
  _Bool _Var3;
  uint8_t uVar4;
  ezb_zcl_status_t eVar5;
  uint uVar6;
  undefined3 extraout_var;
  zcl_attr_desc_t *pzVar7;
  zcl_attr_desc_t *pzVar8;
  undefined3 extraout_var_00;
  zcl_attr_desc_t *pzVar9;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  uint16_t attr_id;
  uint uVar10;
  code *pcVar11;
  uint uVar12;
  uint16_t uStack_72;
  uint8_t uStack_70;
  uint16_t offset;
  ezb_zcl_level_move_to_level_cmd_payload_t payload;
  uint8_t uStack_66;
  uint8_t uStack_65;
  zcl_cvc_input_t input;
  zcl_packet_t rsp;
  
  iVar2 = 1;
  memset(&input.data,0,0x28);
  if (arg == (void *)0x0) goto _L0;
  iVar2 = 1;
  if (((*(byte *)((int)arg + 0x1a) >> 3 & 1) != 0) ||
     (iVar2 = zcl_packet_init(&input.data,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar2 != 0))
  goto _L0;
  cmd_id = *(byte *)((int)arg + 0x20);
  eVar5 = '\0';
  if (cmd_id == 4) {
_L0:
    uVar4 = *(uint8_t *)((int)arg + 0x15);
    uStack_72 = 0;
    _uStack_70 = 0;
    payload.level = '\0';
    payload._1_1_ = 0;
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,&stack0xffffff90);
    uVar12 = (uint)uStack_72;
    iVar2 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),uVar12,2,&offset);
    if (iVar2 == 0) {
      uVar12 = 0xffff;
    }
    else {
      uVar12 = uVar12 + iVar2 & 0xffff;
    }
    uStack_72 = (uint16_t)uVar12;
    uVar6 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
    if (uVar6 < uVar12) {
_L0:
      eVar5 = 0x80;
    }
    else {
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,&payload.level);
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,&payload.field_0x1);
      _Var3 = level_check_options_is_exec(uVar4,cmd_id,payload.level,payload._1_1_);
      if (CONCAT31(extraout_var,_Var3) != 0) {
        cVar1 = *(char *)((int)arg + 0x20);
        stack0xffffff98 = CONCAT31(stack0xffffff99,uVar4);
        pzVar7 = level_srv_get_attr_desc(uVar4,0);
                    /* WARNING: Load size is inaccurate */
        input._0_4_ = ZEXT14(*pzVar7->data_p);
        input.duration._0_1_ = 0;
        input.begin = _uStack_70 & 0xff;
        input.end._0_2_ = 1;
        input._12_4_ = _uStack_70 >> 0x10;
        if (cVar1 == '\0') {
          pcVar11 = level_cvc_output_handler;
        }
        else {
          pcVar11 = level_cvc_with_on_off_output_handler;
        }
        input.cb = (zcl_cvc_output_callback_t)0x0;
        input._20_4_ = pcVar11;
        pzVar7 = level_srv_get_attr_desc(uVar4,2);
        pzVar8 = level_srv_get_attr_desc(uVar4,3);
        uVar12 = 0;
        if (pzVar7 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
          uVar12 = (uint)*pzVar7->data_p;
        }
        uVar6 = 0xff;
        if (pzVar8 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
          uVar6 = (uint)*pzVar8->data_p;
        }
        input.begin = _uStack_70 & 0xff;
        if ((int)input._0_4_ < input.begin) {
          if (uVar6 < (uint)input.begin) {
            input.begin = uVar6;
          }
        }
        else if ((uint)input.begin < uVar12) {
          input.begin = uVar12;
        }
        uVar12 = _uStack_70 >> 0x10;
        if ((uVar12 == 0xffff) &&
           (pzVar7 = level_srv_get_attr_desc(uVar4,0x10), pzVar7 != (zcl_attr_desc_t *)0x0)) {
                    /* WARNING: Load size is inaccurate */
          uVar12 = (uint)*pzVar7->data_p;
        }
_L0:
        input._12_4_ = uVar12;
        eVar5 = schedule_cvc_level(uVar4,(zcl_cvc_input_t *)&payload.options_mask);
      }
    }
  }
  else {
    if (cmd_id < 5) {
      if (cmd_id == 2) {
_L0:
        uVar4 = *(uint8_t *)((int)arg + 0x15);
        uStack_72 = 0;
        _uStack_70 = 0;
        payload.level = '\0';
        payload._1_1_ = 0;
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,&stack0xffffff90);
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,&stack0xffffff91);
        uVar12 = (uint)uStack_72;
        iVar2 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),uVar12,2,&offset);
        if (iVar2 == 0) {
          uVar12 = 0xffff;
        }
        else {
          uVar12 = uVar12 + iVar2 & 0xffff;
        }
        uStack_72 = (uint16_t)uVar12;
        uVar6 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
        if (uVar12 <= uVar6) {
          af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,&payload.level);
          af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,&payload.field_0x1);
          _Var3 = level_check_options_is_exec(uVar4,cmd_id,payload.level,payload._1_1_);
          if (CONCAT31(extraout_var_01,_Var3) == 0) goto _L0;
          cVar1 = *(char *)((int)arg + 0x20);
          pzVar7 = level_srv_get_attr_desc(uVar4,0);
          pzVar8 = level_srv_get_attr_desc(uVar4,2);
          pzVar9 = level_srv_get_attr_desc(uVar4,3);
          uVar12 = 0;
          if (pzVar8 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
            uVar12 = (uint)*pzVar8->data_p;
          }
          uVar6 = 0xff;
          if (pzVar9 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
            uVar6 = (uint)*pzVar9->data_p;
          }
          input._12_4_ = _uStack_70 >> 0x10;
                    /* WARNING: Load size is inaccurate */
          input._0_4_ = ZEXT14(*pzVar7->data_p);
          stack0xffffff98 = CONCAT31(stack0xffffff99,uVar4);
          if (cVar1 == '\x02') {
            pcVar11 = level_cvc_output_handler;
          }
          else {
            pcVar11 = level_cvc_with_on_off_output_handler;
          }
          uVar10 = _uStack_70 >> 8 & 0xff;
          input._20_4_ = pcVar11;
          if (uStack_70 == '\0') {
            input.begin = uVar10 + input._0_4_;
            if ((uVar6 <= uVar10 + input._0_4_) && (input.begin = uVar6, uVar10 != 0)) {
              input._12_4_ = ((uVar6 - input._0_4_) * input._12_4_) / uVar10;
            }
          }
          else {
            input.begin = input._0_4_ - uVar10;
            if (((int)(input._0_4_ - uVar10) <= (int)uVar12) && (input.begin = uVar12, uVar10 != 0))
            {
              input._12_4_ = ((input._0_4_ - uVar12) * input._12_4_) / uVar10;
            }
          }
_L0:
          input.cb = (zcl_cvc_output_callback_t)0x0;
          input.duration._0_1_ = 0;
          input.end._0_2_ = 1;
          uVar12 = input._12_4_;
          goto _L0;
        }
        goto _L0;
      }
      if (cmd_id != 3) {
        if (cmd_id != 0) goto _L0;
        goto _L0;
      }
    }
    else if (cmd_id != 7) {
      if (cmd_id < 8) {
        if (cmd_id != 5) goto _L0;
_L0:
        uVar4 = *(uint8_t *)((int)arg + 0x15);
        uStack_72 = 0;
        _uStack_70 = 0;
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,&stack0xffffff90);
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,&stack0xffffff91);
        uVar12 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
        if (uVar12 < uStack_72) goto _L0;
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,(uint8_t *)&offset);
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,(uint8_t *)((int)&offset + 1));
        _Var3 = level_check_options_is_exec(uVar4,cmd_id,(uint8_t)offset,offset._1_1_);
        if (CONCAT31(extraout_var_00,_Var3) != 0) {
          cVar1 = *(char *)((int)arg + 0x20);
          pzVar7 = level_srv_get_attr_desc(uVar4,2);
          pzVar8 = level_srv_get_attr_desc(uVar4,3);
          pzVar9 = level_srv_get_attr_desc(uVar4,0x14);
          input.begin = 0;
          if (pzVar7 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
            input.begin = (int32_t)*pzVar7->data_p;
          }
          uVar12 = 0xff;
          if (pzVar8 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
            uVar12 = (uint)*pzVar8->data_p;
          }
          stack0xffffff98 = CONCAT31(stack0xffffff99,uVar4);
          pzVar7 = level_srv_get_attr_desc(uVar4,0);
                    /* WARNING: Load size is inaccurate */
          input._0_4_ = ZEXT14(*pzVar7->data_p);
          if (uStack_70 == '\0') {
            input.begin = uVar12;
          }
          if (cVar1 == '\x01') {
            pcVar11 = level_cvc_output_handler;
          }
          else {
            pcVar11 = level_cvc_with_on_off_output_handler;
          }
          uVar12 = _uStack_70 >> 8 & 0xff;
          input._20_4_ = pcVar11;
          if (uVar12 == 0xff) {
            if (pzVar9 == (zcl_attr_desc_t *)0x0) {
              input.quant = 0xffff;
              input._14_2_ = 0;
            }
            else {
              iVar2 = input._0_4_ - input.begin;
              if ((uint)input._0_4_ < (uint)input.begin) {
                iVar2 = input.begin - input._0_4_;
              }
                    /* WARNING: Load size is inaccurate */
              input._12_4_ = (iVar2 * 10) / (int)(uint)*pzVar9->data_p;
            }
          }
          else {
            iVar2 = input._0_4_ - input.begin;
            if ((uint)input._0_4_ < (uint)input.begin) {
              iVar2 = input.begin - input._0_4_;
            }
            input._12_4_ = (iVar2 * 10) / (int)uVar12;
          }
          goto _L0;
        }
      }
      else if (cmd_id == 8) {
        stack0xffffff98 = stack0xffffff98 & 0xffff0000;
        uVar12 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),0,2,&payload.options_mask);
        if (uVar12 == 0) {
          uVar12 = 0xffff;
        }
        uVar6 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
        eVar5 = (uVar12 <= uVar6) + 0x80;
      }
      else {
        eVar5 = 0x81;
      }
      goto _L0;
    }
    uVar4 = *(uint8_t *)((int)arg + 0x15);
    _uStack_70 = _uStack_70 & 0xffff0000;
    stack0xffffff98 = 0;
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),(uint16_t *)&stack0xffffff90,&uStack_66);
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),(uint16_t *)&stack0xffffff90,&uStack_65);
    _Var3 = level_check_options_is_exec(uVar4,cmd_id,uStack_66,uStack_65);
    if (CONCAT31(extraout_var_02,_Var3) != 0) {
      pzVar7 = level_srv_get_attr_desc(uVar4,attr_id);
      if (pzVar7 == (zcl_attr_desc_t *)0x0) {
        eVar5 = 0x86;
      }
      else {
        zcl_cvc_stop(pzVar7->data_p);
      }
    }
  }
_L0:
  iVar2 = zcl_packet_setup_default_response(&input.data,arg,eVar5);
  if (iVar2 == 0) {
    zcl_packet_send(&input.data,0);
  }
  else {
    zcl_packet_free(&input.data);
  }
_L0:
  return (ezb_zcl_status_t)iVar2;
}

