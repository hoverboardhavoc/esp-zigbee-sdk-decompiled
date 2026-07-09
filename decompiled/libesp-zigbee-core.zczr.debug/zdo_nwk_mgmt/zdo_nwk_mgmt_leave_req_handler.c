/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
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
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  int iVar6;
  int *piVar7;
  code *pcStack_38;
  void *pvStack_34;
  undefined1 auStack_30 [4];
  int iStack_2c;
  int iStack_28;
  undefined2 uStack_24;
  
  iStack_2c = 0;
  iStack_28 = 0;
  uStack_24 = 0;
  auStack_30[0] = 0;
  pcStack_38 = (code *)0x0;
  pvStack_34 = (void *)0x0;
  if (param_1 == 0) {
    uVar4 = 0xfe;
  }
  else if (*(int *)(param_1 + 0x14) == 0) {
    uVar4 = 0xfe;
  }
  else if (param_2 == 0) {
    uVar4 = 0xfe;
  }
  else {
    iVar3 = zdo_op_nwk_mgmt_leave_req(&iStack_2c,0);
    if (iVar3 == 0) {
      uVar1 = *(ushort *)(param_1 + 4);
      uVar4 = nwk_get_short_address();
      if (iStack_2c == 0 && iStack_28 == 0) {
        bVar2 = true;
      }
      else {
        piVar7 = (int *)nwk_get_extended_address();
        if ((iStack_2c == *piVar7) && (iStack_28 == piVar7[1])) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
      }
      if (((uVar1 == uVar4) ||
          (iVar3 = nwk_validate_leave_request
                             (*(undefined2 *)(param_1 + 4),*(undefined2 *)(param_1 + 2),
                              uStack_24._1_1_), iVar3 != 0)) ||
         (iVar3 = zdo_nwk_mgmt_leave_is_own_child(&iStack_2c), iVar3 != 0)) {
        iVar3 = zdo_create_mgmt_req(0x34);
        if (iVar3 == 0) {
          uVar4 = 0xfe;
        }
        else {
          puVar5 = (undefined1 *)zdo_mgmt_req_get_param();
          *puVar5 = (char)iStack_2c;
          puVar5[1] = (char)((uint)iStack_2c >> 8);
          puVar5[2] = (char)((uint)iStack_2c >> 0x10);
          puVar5[3] = (char)((uint)iStack_2c >> 0x18);
          puVar5[4] = (char)iStack_28;
          puVar5[5] = (char)((uint)iStack_28 >> 8);
          puVar5[6] = (char)((uint)iStack_28 >> 0x10);
          puVar5[7] = (char)((uint)iStack_28 >> 0x18);
          iVar6 = zdo_mgmt_req_get_param(iVar3);
          *(byte *)(iVar6 + 8) = *(byte *)(iVar6 + 8) & 0xfd | (byte)(((byte)uStack_24 & 1) << 1);
          iVar6 = zdo_mgmt_req_get_param(iVar3);
          *(byte *)(iVar6 + 8) = *(byte *)(iVar6 + 8) & 0xfe | uStack_24._1_1_ & 1;
          if (bVar2) {
            uVar4 = zdo_op_nwk_mgmt_leave_rsp(*(undefined4 *)(param_2 + 0x14),auStack_30,1);
            if (uVar4 == 0) {
              *(code **)(param_2 + 0xc) = zdo_mgmt_leave_rsp_confirm;
              *(int *)(param_2 + 0x10) = iVar3;
              *(undefined1 *)(param_2 + 8) = 0;
            }
          }
          else {
            uVar4 = zdo_op_nwk_mgmt_leave_rsp(*(undefined4 *)(param_2 + 0x14),auStack_30,1);
            if (uVar4 == 0) {
              pvStack_34 = calloc(1,0x18);
              if (pvStack_34 == (void *)0x0) {
                uVar4 = 0x8a;
              }
              else {
                uVar4 = zdo_packet_move(param_2);
                uVar4 = uVar4 & 0xff;
                if (uVar4 == 0) {
                  pcStack_38 = zdo_mgmt_leave_sync_rsp_cb;
                  zdo_mgmt_req_set_user_ctx(iVar3,&pcStack_38);
                  zdo_send_mgmt_req(iVar3,0);
                  uVar4 = 0xfe;
                }
                else {
                  mm_free(pvStack_34);
                }
              }
            }
          }
        }
      }
      else {
        auStack_30[0] = 0x84;
        uVar4 = zdo_op_nwk_mgmt_leave_rsp(*(undefined4 *)(param_2 + 0x14),auStack_30,1);
      }
    }
    else {
      uVar4 = 0xfe;
    }
  }
  return uVar4;
}

