/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> identify.o -> identify_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t identify_cluster_srv_cmd_proc_handler(void *arg)

{
  char cVar1;
  byte ep_id;
  uint8_t ep_id_00;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  _Bool _Var5;
  uint uVar6;
  uint uVar7;
  zcl_attr_desc_t *pzVar8;
  zcl_attr_desc_t *pzVar9;
  undefined3 extraout_var;
  int iVar10;
  uint uVar11;
  uint16_t attr_id;
  uint16_t attr_id_00;
  uint16_t attr_id_01;
  undefined1 uStack_5e;
  undefined1 uStack_5d;
  uint16_t uStack_5c;
  uint8_t effect_id;
  uint8_t effect_variant;
  uint16_t identify_time;
  void *pvStack_54;
  undefined4 uStack_50;
  uint uStack_4c;
  undefined1 auStack_48 [4];
  zcl_packet_t rsp;
  
  memset(auStack_48,0,0x28);
  if (arg == (void *)0x0) {
    iVar4 = 1;
    goto _L0;
  }
  iVar4 = 1;
  if (((*(byte *)((int)arg + 0x1a) >> 3 & 1) != 0) ||
     (iVar4 = zcl_packet_init(auStack_48,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar4 != 0))
  goto _L0;
  cVar1 = *(char *)((int)arg + 0x20);
  if (cVar1 == '\x01') {
    ep_id_00 = *(uint8_t *)((int)arg + 0x15);
    _Var5 = ezb_zcl_is_identifying(ep_id_00);
    if (CONCAT31(extraout_var,_Var5) != 0) {
      pzVar8 = identify_srv_get_attr_desc(ep_id_00,attr_id_01);
      if ((pzVar8 == (zcl_attr_desc_t *)0x0) || ((undefined2 *)pzVar8->data_p == (undefined2 *)0x0))
      {
        uVar6 = 0x86;
      }
      else {
                    /* WARNING: Load size is inaccurate */
        _uStack_5c = CONCAT22(_effect_id,*pzVar8->data_p);
        uVar6 = zmsg_append_bytes(rsp._32_4_,2,&stack0xffffffa4);
        uVar6 = uVar6 & 0xff;
        if (uVar6 == 0) goto _L0;
      }
      goto _L0;
    }
_L0:
    iVar4 = zmsg_get_length(rsp._32_4_);
    uVar6 = 0;
    if (iVar4 == 0) goto _L0;
    iVar4 = zcl_packet_setup_response(auStack_48,arg,0);
  }
  else {
    if (cVar1 == '@') {
      uStack_5e = 0;
      uStack_5d = 0;
      iVar4 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),0,&uStack_5e);
      if (iVar4 == 0) {
        iVar4 = 0xffff;
      }
      iVar10 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),iVar4,1,&uStack_5d);
      if (iVar10 == 0) {
        uVar7 = 0xffff;
      }
      else {
        uVar7 = iVar10 + iVar4 & 0xffff;
      }
      uVar11 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
      uVar3 = uStack_5d;
      uVar2 = uStack_5e;
      uVar6 = 0x80;
      if (uVar7 <= uVar11) {
        _uStack_5c = 0;
        _identify_time = 0;
        pvStack_54 = (void *)0x0;
        uStack_50 = 0;
        uStack_4c = 0;
        iVar4 = zcl_packet_to_message(&stack0xffffffa4,arg,0x80);
        if (iVar4 == 0) {
          uStack_4c = CONCAT31(uStack_4c._1_3_,0xfe);
          uStack_50._0_2_ = CONCAT11(uVar3,uVar2);
          pvStack_54 = arg;
          zcl_core_action_schedule(10,&stack0xffffffa4);
          uVar6 = uStack_4c & 0xff;
          if (uVar6 != 0xfe) goto _L0;
        }
        uVar6 = 0;
      }
    }
    else if (cVar1 == '\0') {
      ep_id = *(byte *)((int)arg + 0x15);
      _uStack_5c = _uStack_5c & 0xffff0000;
      uVar6 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),0,2,&stack0xffffffa4);
      if (uVar6 == 0) {
        uVar6 = 0xffff;
      }
      uVar7 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
      if (uVar7 < uVar6) {
        uVar6 = 0x80;
      }
      else {
        pzVar8 = identify_srv_get_attr_desc(ep_id,attr_id);
        pzVar9 = identify_srv_get_attr_desc(ep_id,attr_id_00);
        if (pzVar9 == (zcl_attr_desc_t *)0x0) {
          __assert_func(0,0,0);
        }
        if ((pzVar8 == (zcl_attr_desc_t *)0x0) || (pzVar8->data_p == (void *)0x0)) {
          uVar6 = 0x86;
        }
        else {
          zcl_message_set_identify_attr_value((ushort)ep_id,uStack_5c);
          uVar6 = 0;
        }
      }
    }
    else {
      uVar6 = 0x81;
    }
_L0:
    iVar4 = zcl_packet_setup_default_response(auStack_48,arg,uVar6);
  }
  if (iVar4 == 0) {
    zcl_packet_send(auStack_48,0);
  }
  else {
    zcl_packet_free(auStack_48);
  }
_L0:
  return (ezb_zcl_status_t)iVar4;
}

