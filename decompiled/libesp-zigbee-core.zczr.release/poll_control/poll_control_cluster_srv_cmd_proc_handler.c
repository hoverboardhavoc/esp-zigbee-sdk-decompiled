/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> poll_control.o -> poll_control_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t poll_control_cluster_srv_cmd_proc_handler(void *arg)

{
  byte bVar1;
  uint8_t ep_id;
  _Bool _Var2;
  int iVar3;
  int iVar4;
  undefined3 extraout_var;
  zcl_attr_desc_t *pzVar5;
  undefined3 extraout_var_00;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  short sVar10;
  char cStack_4d;
  short sStack_4c;
  undefined2 uStack_4a;
  _Bool start_fast_poll;
  uint16_t fast_poll_timeout;
  zcl_packet_t rsp;
  
  memset(&fast_poll_timeout,0,0x28);
  if ((arg != (void *)0x0) && ((*(byte *)((int)arg + 0x1a) >> 3 & 1) == 0)) {
    iVar3 = zcl_packet_init(&fast_poll_timeout,*(byte *)((int)arg + 0x1a) >> 2 & 1);
    if (iVar3 != 0) goto _L0;
    bVar1 = *(byte *)((int)arg + 0x20);
    if (bVar1 == 2) {
      _sStack_4c = 0;
      uVar6 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
      uVar7 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),0,4,&stack0xffffffb4);
      if (uVar7 == 0) {
        uVar7 = 0xffff;
      }
      else {
        uVar8 = uVar7 & 0xff;
        if (uVar8 != 0) goto _L0;
      }
      uVar8 = 0x80;
      if (uVar7 <= uVar6) {
        ep_id = *(uint8_t *)((int)arg + 0x15);
        uVar8 = 0x86;
        pzVar5 = poll_control_srv_get_attr_desc(ep_id,1);
        if (pzVar5 != (zcl_attr_desc_t *)0x0) {
          uVar9 = 1;
_L154:
          uVar8 = ezb_zcl_set_attr_value(ep_id,0x20,1,uVar9,0,&stack0xffffffb4,0);
          if (uVar8 == 0) {
            zcl_message_notify_attr_value(ep_id,0x20,1,pzVar5);
          }
        }
      }
    }
    else if (bVar1 < 3) {
      if (bVar1 == 0) {
        cStack_4d = '\0';
        _sStack_4c = _sStack_4c & 0xffff0000;
        iVar3 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),0,1,&cStack_4d);
        if (iVar3 == 0) {
          iVar3 = 0xffff;
        }
        iVar4 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),iVar3,2,&stack0xffffffb4);
        if ((iVar4 == 0) || ((iVar3 + iVar4 & 0xffffU) != 0)) {
          uVar8 = 0x80;
        }
        else {
          _Var2 = poll_control_source_is_exist_in_bind_table
                            (*(uint8_t *)((int)arg + 0x14),*(uint16_t *)((int)arg + 2));
          if (CONCAT31(extraout_var,_Var2) == 0) {
            uVar8 = 1;
          }
          else {
            uVar8 = 0;
            if (cStack_4d != '\0') {
              pzVar5 = poll_control_srv_get_attr_desc(*(uint8_t *)((int)arg + 0x15),3);
              if (pzVar5 == (zcl_attr_desc_t *)0x0) {
_L106:
                __assert_func(0,0,0,0);
                goto _L0;
              }
              sVar10 = sStack_4c;
              if (sStack_4c == 0) {
                    /* WARNING: Load size is inaccurate */
                sVar10 = *pzVar5->data_p;
              }
              _sStack_4c = CONCAT22(uStack_4a,sVar10);
              pzVar5 = poll_control_srv_get_attr_desc(*(uint8_t *)((int)arg + 0x15),6);
              uVar6 = _sStack_4c & 0xffff;
                    /* WARNING: Load size is inaccurate */
              if ((pzVar5 == (zcl_attr_desc_t *)0x0) || (uVar6 <= *pzVar5->data_p)) {
                pzVar5 = poll_control_srv_get_attr_desc(*(uint8_t *)((int)arg + 0x15),2);
                    /* WARNING: Load size is inaccurate */
                if ((pzVar5 == (zcl_attr_desc_t *)0x0) ||
                   (uVar7 = (uint)*pzVar5->data_p * 0xfa, uVar7 == 0)) goto _L106;
                nwk_pim_set_fast_poll_interval(uVar7);
                nwk_pim_start_fast_poll((uVar6 * 0xfa) / uVar7 & 0xffff);
              }
              else {
                uVar8 = 0x85;
              }
            }
          }
        }
      }
      else {
        _Var2 = poll_control_source_is_exist_in_bind_table
                          (*(uint8_t *)((int)arg + 0x14),*(uint16_t *)((int)arg + 2));
        if ((CONCAT31(extraout_var_00,_Var2) == 0) ||
           (iVar3 = nwk_pim_is_fast_poll_running(), iVar3 == 0)) {
          uVar8 = 1;
        }
        else {
          nwk_pim_stop_fast_poll();
          uVar8 = nwk_pim_is_fast_poll_running();
        }
      }
    }
    else {
_L0:
      if (bVar1 == 3) {
        _sStack_4c = _sStack_4c & 0xffff0000;
        uVar6 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
        uVar7 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),0,2,&stack0xffffffb4);
        if (uVar7 == 0) {
          uVar7 = 0xffff;
        }
        else {
          uVar8 = uVar7 & 0xff;
          if (uVar8 != 0) goto _L0;
        }
        uVar8 = 0x80;
        if (uVar7 <= uVar6) {
          ep_id = *(uint8_t *)((int)arg + 0x15);
          uVar8 = 0x86;
          pzVar5 = poll_control_srv_get_attr_desc(ep_id,2);
          if (pzVar5 != (zcl_attr_desc_t *)0x0) {
            uVar9 = 2;
            goto _L154;
          }
        }
      }
      else {
        uVar8 = 0x81;
      }
    }
_L0:
    iVar3 = zcl_packet_setup_default_response(&fast_poll_timeout,arg,uVar8);
    if (iVar3 != 0) {
      zcl_packet_free(&fast_poll_timeout);
      goto _L0;
    }
    zcl_packet_send(&fast_poll_timeout,0);
  }
  iVar3 = 0;
_L0:
  return (ezb_zcl_status_t)iVar3;
}

