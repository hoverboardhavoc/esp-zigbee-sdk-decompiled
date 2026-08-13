/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_leave_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zdo_nwk_mgmt_leave_req_handler(int param_1,int param_2)

{
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined1 *puVar7;
  int *piVar8;
  code *pcStack_38;
  void *pvStack_34;
  char acStack_30 [4];
  int iStack_2c;
  int iStack_28;
  undefined2 uStack_24;
  
  iStack_2c = 0;
  iStack_28 = 0;
  uStack_24 = 0;
  acStack_30[0] = '\0';
  pcStack_38 = (code *)0x0;
  pvStack_34 = (void *)0x0;
  if (param_1 == 0) {
    return 0xfe;
  }
  if (*(int *)(param_1 + 0x14) == 0) {
    return 0xfe;
  }
  if (param_2 == 0) {
    return 0xfe;
  }
  iVar4 = zdo_op_nwk_mgmt_leave_req(&iStack_2c,0);
  if (iVar4 != 0) {
    return 0xfe;
  }
  uVar1 = *(ushort *)(param_1 + 4);
  uVar5 = nwk_get_short_address();
  if (iStack_2c == 0 && iStack_28 == 0) {
    bVar2 = true;
  }
  else {
    piVar8 = (int *)nwk_get_extended_address();
    if ((iStack_2c == *piVar8) && (iStack_28 == piVar8[1])) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
  }
  acStack_30[0] = '\0';
  if (uVar1 == uVar5) goto _L0;
  if (bVar2) {
    iVar4 = nwk_validate_leave_request
                      (*(undefined2 *)(param_1 + 4),*(undefined2 *)(param_1 + 2),uStack_24._1_1_);
  }
  else {
    iVar4 = 1;
  }
  iVar6 = nwk_is_device_zed();
  if (iVar6 == 0) {
    if (bVar2) {
      bVar3 = true;
    }
    else {
      iVar6 = zdo_nwk_mgmt_leave_is_own_child(&iStack_2c);
      if (iVar6 == 0) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
    }
    if (iVar4 != 0) goto _L0;
    acStack_30[0] = -0x73;
  }
  else {
    bVar3 = bVar2;
    if ((iVar4 == 0) &&
       (iVar4 = zdo_nwk_mgmt_leave_is_from_tc(*(undefined2 *)(param_1 + 4)), iVar4 == 0)) {
      acStack_30[0] = -0x73;
    }
    else {
_L0:
      if (bVar3) {
        acStack_30[0] = '\0';
      }
      else {
        acStack_30[0] = -0x7c;
      }
    }
  }
  if (acStack_30[0] != '\0') {
    zdo_op_nwk_mgmt_leave_rsp(*(undefined4 *)(param_2 + 0x14),acStack_30,1);
    return 0;
  }
_L0:
  iVar4 = zdo_create_mgmt_req(0x34);
  if (iVar4 == 0) {
    uVar5 = 0xfe;
  }
  else {
    puVar7 = (undefined1 *)zdo_mgmt_req_get_param();
    *puVar7 = (char)iStack_2c;
    puVar7[1] = (char)((uint)iStack_2c >> 8);
    puVar7[2] = (char)((uint)iStack_2c >> 0x10);
    puVar7[3] = (char)((uint)iStack_2c >> 0x18);
    puVar7[4] = (char)iStack_28;
    puVar7[5] = (char)((uint)iStack_28 >> 8);
    puVar7[6] = (char)((uint)iStack_28 >> 0x10);
    puVar7[7] = (char)((uint)iStack_28 >> 0x18);
    iVar6 = zdo_mgmt_req_get_param(iVar4);
    *(byte *)(iVar6 + 8) = *(byte *)(iVar6 + 8) & 0xfd | (byte)(((byte)uStack_24 & 1) << 1);
    iVar6 = zdo_mgmt_req_get_param(iVar4);
    *(byte *)(iVar6 + 8) = *(byte *)(iVar6 + 8) & 0xfe | uStack_24._1_1_ & 1;
    if (bVar2) {
      uVar5 = zdo_op_nwk_mgmt_leave_rsp(*(undefined4 *)(param_2 + 0x14),acStack_30,1);
      if (uVar5 == 0) {
        *(code **)(param_2 + 0xc) = zdo_mgmt_leave_rsp_confirm;
        *(int *)(param_2 + 0x10) = iVar4;
        *(undefined1 *)(param_2 + 8) = 0;
      }
    }
    else {
      uVar5 = zdo_op_nwk_mgmt_leave_rsp(*(undefined4 *)(param_2 + 0x14),acStack_30,1);
      if (uVar5 == 0) {
        pvStack_34 = calloc(1,0x18);
        if (pvStack_34 == (void *)0x0) {
          uVar5 = 0x8a;
        }
        else {
          uVar5 = zdo_packet_move(param_2);
          uVar5 = uVar5 & 0xff;
          if (uVar5 == 0) {
            pcStack_38 = zdo_mgmt_leave_sync_rsp_cb;
            zdo_mgmt_req_set_user_ctx(iVar4,&pcStack_38);
            zdo_send_mgmt_req(iVar4,0);
            uVar5 = 0xfe;
          }
          else {
            mm_free(pvStack_34);
          }
        }
      }
    }
  }
  return uVar5;
}

