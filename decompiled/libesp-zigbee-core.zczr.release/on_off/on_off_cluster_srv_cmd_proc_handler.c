/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> on_off.o -> on_off_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t on_off_cluster_srv_cmd_proc_handler(void *arg)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  char cVar4;
  int iVar5;
  uint8_t uVar6;
  int iVar7;
  zcl_attr_desc_t *pzVar8;
  uint uVar9;
  zcl_attr_desc_t *pzVar10;
  zcl_attr_desc_t *pzVar11;
  uint8_t uVar12;
  uint32_t delay;
  bool on_off;
  uint uVar13;
  ushort uVar14;
  ushort uVar15;
  ushort uVar16;
  uint uVar17;
  undefined1 uStack_61;
  undefined1 uStack_60;
  byte bStack_5f;
  ushort uStack_5e;
  uint8_t effect_id;
  uint8_t effect_variant;
  uint8_t on_off_control;
  uint16_t on_time;
  uint16_t off_wait_time;
  void *pvStack_54;
  undefined4 uStack_50;
  uint uStack_4c;
  undefined1 auStack_48 [4];
  zcl_packet_t rsp;
  
  memset(auStack_48,0,0x28);
  if (arg == (void *)0x0) {
    iVar5 = 1;
    goto _L0;
  }
  iVar5 = 1;
  if (((*(byte *)((int)arg + 0x1a) >> 3 & 1) != 0) ||
     (iVar5 = zcl_packet_init(auStack_48,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar5 != 0))
  goto _L0;
  bVar1 = *(byte *)((int)arg + 0x20);
  uVar6 = '\0';
  if (bVar1 == 0x40) {
    uVar12 = *(uint8_t *)((int)arg + 0x15);
    uStack_61 = 0;
    uStack_60 = 0;
    iVar5 = af_get_ep_desc(uVar12);
    if (iVar5 == 0) goto _L133;
    iVar5 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),0,1,&uStack_61);
    if (iVar5 == 0) {
      iVar5 = 0xffff;
    }
    iVar7 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),iVar5,1,&uStack_60);
    if (iVar7 == 0) {
      uVar17 = 0xffff;
    }
    else {
      uVar17 = iVar7 + iVar5 & 0xffff;
    }
    uVar9 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
    uVar13 = 0x80;
    if (uVar17 <= uVar9) {
      pzVar8 = on_off_srv_get_attr_desc(uVar12,0x4000);
                    /* WARNING: Load size is inaccurate */
      if ((pzVar8 != (zcl_attr_desc_t *)0x0) && (*pzVar8->data_p != '\0')) {
        zcl_message_scenes_store_scene(uVar12,0,0);
        *(undefined1 *)pzVar8->data_p = 0;
      }
      uVar3 = uStack_60;
      uVar2 = uStack_61;
      _effect_variant = 0;
      _off_wait_time = 0;
      pvStack_54 = (void *)0x0;
      uStack_50 = 0;
      uStack_4c = 0;
      uVar13 = zcl_packet_to_message(&effect_variant,arg);
      if (uVar13 == 0) {
        uStack_4c = CONCAT31(uStack_4c._1_3_,0xfe);
        uStack_50._0_2_ = CONCAT11(uVar3,uVar2);
        pvStack_54 = arg;
        zcl_core_action_schedule(0xc,&effect_variant,0);
        uVar13 = uStack_4c & 0xff;
        if ((uVar13 == 0xfe) || (uVar13 == 0)) {
          on_off = false;
          uVar12 = '@';
          goto _L0;
        }
      }
    }
    goto _L0;
  }
  if (bVar1 < 0x41) {
    if (bVar1 == 1) {
      on_off = true;
      uVar12 = '\x01';
_L0:
      uVar6 = *(uint8_t *)((int)arg + 0x15);
    }
    else {
      if (bVar1 != 2) {
        if (bVar1 != 0) goto _L0;
        on_off = false;
        uVar12 = '\0';
        goto _L0;
      }
      uVar6 = *(uint8_t *)((int)arg + 0x15);
      pzVar8 = on_off_srv_get_attr_desc(uVar6,0);
      if (pzVar8 == (zcl_attr_desc_t *)0x0) goto _L133;
_L0:
                    /* WARNING: Load size is inaccurate */
      uVar12 = *pzVar8->data_p == '\0';
      on_off = (bool)uVar12;
    }
    on_off_process_transition(uVar6,uVar12,on_off,0,0);
    uVar13 = 0;
_L0:
    iVar5 = zcl_packet_setup_default_response(auStack_48,arg,uVar13);
_L0:
    if (iVar5 == 0) {
      zcl_packet_send(auStack_48,0);
      goto _L0;
    }
  }
  else {
    if (bVar1 == 0x41) {
      uVar12 = *(uint8_t *)((int)arg + 0x15);
      iVar5 = af_get_ep_desc(uVar12);
      if (iVar5 == 0) goto _L133;
      pzVar8 = on_off_srv_get_attr_desc(uVar12,0x4000);
      uVar13 = 0x86;
      if ((pzVar8 != (zcl_attr_desc_t *)0x0) && ((char *)pzVar8->data_p != (char *)0x0)) {
                    /* WARNING: Load size is inaccurate */
        if (*pzVar8->data_p == '\0') {
          zcl_scenes_recall_scene(arg,0,0,0);
          *(undefined1 *)pzVar8->data_p = 1;
          on_off_process_transition(uVar12,'A','\x01',0,0);
          uVar13 = 0;
        }
        else {
          uVar13 = 0xfe;
        }
      }
      goto _L0;
    }
    if (bVar1 != 0x42) {
_L0:
      uVar13 = 0x81;
      goto _L0;
    }
    uVar12 = *(uint8_t *)((int)arg + 0x15);
    bStack_5f = 0;
    uStack_5e = 0;
    _effect_variant = _effect_variant & 0xffff0000;
    iVar5 = af_get_ep_desc(uVar12);
    if (iVar5 == 0) {
_L133:
      pzVar8 = (zcl_attr_desc_t *)__assert_func(0,0,0,0);
      goto _L0;
    }
    iVar5 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),0,1,&bStack_5f);
    if (iVar5 == 0) {
      iVar5 = 0xffff;
    }
    iVar7 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),iVar5,2,&stack0xffffffa2);
    if (iVar7 == 0) {
      uVar17 = 0xffff;
    }
    else {
      uVar17 = iVar5 + iVar7 & 0xffff;
    }
    iVar5 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),uVar17,2,&effect_variant);
    if (iVar5 == 0) {
      uVar17 = 0xffff;
    }
    else {
      uVar17 = uVar17 + iVar5 & 0xffff;
    }
    uVar13 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
    if (uVar17 <= uVar13) {
      pzVar8 = on_off_srv_get_attr_desc(uVar12,0);
      pzVar10 = on_off_srv_get_attr_desc(uVar12,0x4001);
      pzVar11 = on_off_srv_get_attr_desc(uVar12,0x4002);
      if (pzVar8 == (zcl_attr_desc_t *)0x0) goto _L133;
      if ((pzVar10 == (zcl_attr_desc_t *)0x0) || (pzVar11 == (zcl_attr_desc_t *)0x0)) {
        uVar13 = 0x8c;
        goto _L0;
      }
      cVar4 = '\0';
      if ((char *)pzVar8->data_p != (char *)0x0) {
                    /* WARNING: Load size is inaccurate */
        cVar4 = *pzVar8->data_p;
      }
      uVar15 = 0;
      if ((ushort *)pzVar10->data_p != (ushort *)0x0) {
                    /* WARNING: Load size is inaccurate */
        uVar15 = *pzVar10->data_p;
      }
      uVar14 = 0;
      if ((ushort *)pzVar11->data_p != (ushort *)0x0) {
                    /* WARNING: Load size is inaccurate */
        uVar14 = *pzVar11->data_p;
      }
      uVar16 = _effect_variant;
      if ((bStack_5f & 1) == 0) {
        if ((uVar14 == 0) || (cVar4 != '\0')) goto _L0;
        if (uVar14 < _effect_variant) {
          uVar16 = uVar14;
        }
        uVar14 = 0;
        uVar6 = '\0';
      }
      else {
        if (cVar4 == '\0') {
          iVar5 = 0xfe;
          goto _L0;
        }
_L0:
        uVar14 = uStack_5e;
        if (uStack_5e < uVar15) {
          uVar14 = uVar15;
        }
        uVar6 = '\x01';
      }
      on_off_process_transition(uVar12,'B',uVar6,uVar14,uVar16);
      iVar5 = zcl_packet_setup_default_response(auStack_48,arg,0);
      if ((uStack_5e != 0xffff) && (_effect_variant != -1)) {
        on_off_timer_start(uVar12,delay);
      }
      goto _L0;
    }
    iVar5 = 0x80;
  }
_L0:
  zcl_packet_free(auStack_48);
_L0:
  return (ezb_zcl_status_t)iVar5;
}

