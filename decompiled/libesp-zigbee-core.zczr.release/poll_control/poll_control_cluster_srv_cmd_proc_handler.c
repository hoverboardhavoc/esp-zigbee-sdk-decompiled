/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> poll_control.o -> poll_control_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int poll_control_cluster_srv_cmd_proc_handler(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined2 uVar8;
  undefined1 uVar9;
  char cStack_4d;
  uint uStack_4c;
  undefined1 auStack_48 [48];
  
  memset(auStack_48,0,0x28);
  if (param_1 == 0) {
    return 0;
  }
  if ((*(byte *)(param_1 + 0x1a) >> 3 & 1) != 0) {
    return 0;
  }
  iVar2 = zcl_packet_init(auStack_48,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar2 != 0) {
    return iVar2;
  }
  bVar1 = *(byte *)(param_1 + 0x20);
  if (bVar1 == 2) {
    uStack_4c = 0;
    uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    uVar5 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),0,4,&uStack_4c);
    if (uVar5 == 0) {
      uVar5 = 0xffff;
    }
    else {
      uVar6 = uVar5 & 0xff;
      if (uVar6 != 0) goto _L0;
    }
    uVar6 = 0x80;
    if (uVar4 < uVar5) goto _L0;
    uVar9 = *(undefined1 *)(param_1 + 0x15);
    uVar6 = 0x86;
    iVar2 = poll_control_srv_get_attr_desc(uVar9,1);
    if (iVar2 == 0) goto _L0;
    uVar7 = 1;
  }
  else {
    if (bVar1 < 3) {
      if (bVar1 != 0) {
        iVar2 = poll_control_source_is_exist_in_bind_table
                          (*(undefined1 *)(param_1 + 0x14),*(undefined2 *)(param_1 + 2));
        if ((iVar2 == 0) || (iVar2 = nwk_pim_is_fast_poll_running(), iVar2 == 0)) {
          uVar6 = 1;
        }
        else {
          nwk_pim_stop_fast_poll();
          uVar6 = nwk_pim_is_fast_poll_running();
        }
        goto _L0;
      }
      cStack_4d = '\0';
      uStack_4c = uStack_4c & 0xffff0000;
      iVar2 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),0,1,&cStack_4d);
      if (iVar2 == 0) {
        iVar2 = 0xffff;
      }
      iVar3 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),iVar2,2,&uStack_4c);
      if ((iVar3 == 0) || ((iVar2 + iVar3 & 0xffffU) != 0)) {
        uVar6 = 0x80;
        goto _L0;
      }
      iVar2 = poll_control_source_is_exist_in_bind_table
                        (*(undefined1 *)(param_1 + 0x14),*(undefined2 *)(param_1 + 2));
      if (iVar2 == 0) {
        uVar6 = 1;
        goto _L0;
      }
      uVar6 = 0;
      if (cStack_4d == '\0') goto _L0;
      iVar2 = poll_control_srv_get_attr_desc(*(undefined1 *)(param_1 + 0x15),3);
      if (iVar2 != 0) {
        uVar8 = (undefined2)uStack_4c;
        if ((uStack_4c & 0xffff) == 0) {
          uVar8 = **(undefined2 **)(iVar2 + 8);
        }
        uStack_4c = CONCAT22(uStack_4c._2_2_,uVar8);
        iVar2 = poll_control_srv_get_attr_desc(*(undefined1 *)(param_1 + 0x15),6);
        uVar4 = uStack_4c & 0xffff;
        if ((iVar2 != 0) && (**(ushort **)(iVar2 + 8) < uVar4)) {
          uVar6 = 0x85;
          goto _L0;
        }
        iVar2 = poll_control_srv_get_attr_desc(*(undefined1 *)(param_1 + 0x15),2);
        if ((iVar2 != 0) && (uVar5 = (uint)**(ushort **)(iVar2 + 8) * 0xfa, uVar5 != 0)) {
          nwk_pim_set_fast_poll_interval(uVar5);
          nwk_pim_start_fast_poll((uVar4 * 0xfa) / uVar5 & 0xffff);
          goto _L0;
        }
      }
      __assert_func(0,0,0,0);
    }
    if (bVar1 != 3) {
      uVar6 = 0x81;
      goto _L0;
    }
    uStack_4c = uStack_4c & 0xffff0000;
    uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    uVar5 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),0,2,&uStack_4c);
    if (uVar5 == 0) {
      uVar5 = 0xffff;
    }
    else {
      uVar6 = uVar5 & 0xff;
      if (uVar6 != 0) goto _L0;
    }
    uVar6 = 0x80;
    if (uVar4 < uVar5) goto _L0;
    uVar9 = *(undefined1 *)(param_1 + 0x15);
    uVar6 = 0x86;
    iVar2 = poll_control_srv_get_attr_desc(uVar9,2);
    if (iVar2 == 0) goto _L0;
    uVar7 = 2;
  }
  uVar6 = ezb_zcl_set_attr_value(uVar9,0x20,1,uVar7,0,&uStack_4c,0);
  if (uVar6 == 0) {
    zcl_message_notify_attr_value(uVar9,0x20,1,iVar2);
  }
_L0:
  iVar2 = zcl_packet_setup_default_response(auStack_48,param_1,uVar6);
  if (iVar2 == 0) {
    zcl_packet_send(auStack_48,0);
    return 0;
  }
  zcl_packet_free(auStack_48);
  return iVar2;
}

