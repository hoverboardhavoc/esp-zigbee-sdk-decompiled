/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_permit_joining_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_nwk_mgmt_permit_joining_req_handler(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  char cVar6;
  undefined1 auStack_28 [4];
  undefined2 uStack_24;
  
  uStack_24 = 0;
  auStack_28[0] = 0;
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
    uVar1 = *(ushort *)(param_1 + 2);
    iVar2 = zdo_op_nwk_mgmt_permit_joining_req(&uStack_24,0);
    if (iVar2 == 0) {
      cVar6 = (char)uStack_24;
      if ((char)uStack_24 == -1) {
        cVar6 = -2;
      }
      uStack_24 = CONCAT11(1,(char)uStack_24);
      nwk_is_device_zc();
      iVar3 = nwk_is_device_zczr();
      if (iVar3 == 0) {
        auStack_28[0] = 0x84;
      }
      else {
        iVar3 = zdo_create_mgmt_req(0x36);
        if (iVar3 == 0) {
          auStack_28[0] = 0x80;
        }
        else {
          pcVar5 = (char *)zdo_mgmt_req_get_param();
          *pcVar5 = cVar6;
          iVar3 = zdo_send_mgmt_req(iVar3,1);
          auStack_28[0] = (char)iVar2;
          if (iVar3 != 0) {
            auStack_28[0] = 0x80;
          }
        }
      }
      if (uVar1 < 0xfff8) {
        uVar4 = zdo_op_nwk_mgmt_permit_joining_rsp(*(undefined4 *)(param_2 + 0x14),auStack_28,1);
      }
      else {
        uVar4 = 0xfe;
      }
    }
    else {
      uVar4 = 0xfe;
    }
  }
  return uVar4;
}

