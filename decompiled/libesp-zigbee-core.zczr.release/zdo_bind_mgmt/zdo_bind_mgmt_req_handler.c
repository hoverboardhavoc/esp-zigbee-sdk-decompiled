/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_bind_mgmt.o -> zdo_bind_mgmt_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_bind_mgmt_req_handler(int param_1)

{
  bool bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  ushort uStack_5e;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined2 uStack_54;
  undefined1 auStack_50 [20];
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  char acStack_30 [2];
  undefined2 uStack_2e;
  char acStack_2c [2];
  undefined2 uStack_2a;
  undefined2 uStack_28;
  undefined1 auStack_22 [10];
  
  memset(auStack_50,0,0x18);
  if (param_1 == 0) {
    return 0x80;
  }
  iVar4 = zdo_packet_response_init(auStack_50,param_1,*(ushort *)(param_1 + 6) | 0x8000);
  if (iVar4 != 0) {
    return iVar4;
  }
  if (1 < *(ushort *)(param_1 + 6) - 0x21) {
    iVar4 = 0x84;
    goto _L0;
  }
  memset(&iStack_38,0,0x18);
  iVar4 = *(int *)(param_1 + 0x14);
  uStack_5c = 0;
  uStack_58 = 0;
  uStack_54 = 0;
  if ((iVar4 != 0) && (*(ushort *)(param_1 + 2) < 0xfff8)) {
    uVar5 = zmsg_get_length(iVar4);
    iVar6 = zmsg_read_bytes(iVar4,0,8,&iStack_38);
    if (iVar6 == 0) {
      iVar6 = 0xffff;
    }
    uStack_5e = (ushort)iVar6;
    af_read_le8_isra_0(iVar4,&uStack_5e,acStack_30);
    uVar2 = uStack_5e;
    iVar6 = zmsg_read_bytes(iVar4,uStack_5e,2,&uStack_2e);
    if (iVar6 == 0) {
      uStack_5e = 0xffff;
    }
    else {
      uStack_5e = uVar2 + (short)iVar6;
    }
    af_read_le8_isra_0(iVar4,&uStack_5e,acStack_2c);
    uVar2 = uStack_5e;
    uVar3 = (uint)uStack_5e;
    if (uVar3 <= uVar5) {
      bVar1 = false;
      if (acStack_2c[0] == '\x03') {
        iVar6 = zmsg_read_bytes(iVar4,uVar3,8,&uStack_2a);
        if (iVar6 == 0) {
          uStack_5e = 0xffff;
        }
        else {
          uStack_5e = uVar2 + (short)iVar6;
        }
        af_read_le8_isra_0(iVar4,&uStack_5e,auStack_22);
      }
      else if (acStack_2c[0] == '\x01') {
        iVar4 = zmsg_read_bytes(iVar4,uVar3,2,&uStack_2a);
        if (iVar4 == 0) {
          uStack_5e = 0xffff;
        }
        else {
          uStack_5e = uVar2 + (short)iVar4;
        }
      }
      else {
        bVar1 = true;
      }
      if ((uStack_5e <= uVar5) && (!bVar1)) {
        iVar4 = nwk_get_extended_address();
        if (iVar4 == 0) goto _L0;
        piVar7 = (int *)nwk_get_extended_address();
        if (iStack_38 != *piVar7) goto _L0;
        if (iStack_34 != piVar7[1]) goto _L0;
        if ((byte)(acStack_30[0] - 1U) < 0xfe) {
          if (acStack_2c[0] == '\x03') {
            uStack_5c = CONCAT31(uStack_5c._1_3_,3);
            memcpy((void *)((int)&uStack_5c + 2),&uStack_2a,8);
          }
          else {
            if (acStack_2c[0] != '\x01') {
              iVar4 = 0x80;
              goto _L0;
            }
            uStack_5c = CONCAT31(uStack_5c._1_3_,1);
            uStack_5c = CONCAT22(uStack_2a,(undefined2)uStack_5c);
            uStack_58 = CONCAT22(uStack_58._2_2_,uStack_28);
          }
          if (*(short *)(param_1 + 6) == 0x21) {
            aps_bind_table_add(&iStack_38,acStack_30[0],uStack_2e,&uStack_5c,auStack_22[0]);
            iVar4 = ezb_err_to_zdp_status();
            if (iVar4 == 0x8a) {
              iVar4 = 0x8c;
            }
            else if (iVar4 == 0xfe) goto _L0;
          }
          else {
            if (*(short *)(param_1 + 6) != 0x22) goto _L0;
            iVar6 = aps_bind_table_remove
                              (&iStack_38,acStack_30[0],uStack_2e,&uStack_5c,auStack_22[0]);
            iVar4 = 0;
            if (iVar6 != 0) {
              iVar4 = 0x88;
            }
          }
        }
        else {
          iVar4 = 0x82;
        }
_L0:
        while (iStack_3c == 0) {
_L0:
          __assert_func(0,0,0,0);
_L0:
          iVar4 = 0x84;
        }
        uStack_5e = CONCAT11(uStack_5e._1_1_,(char)iVar4);
        iVar4 = zmsg_append_bytes(1,&uStack_5e);
        if (iVar4 == 0) {
          iVar4 = zdo_packet_send(auStack_50);
          return iVar4;
        }
        iVar4 = 0x8a;
        goto _L0;
      }
    }
  }
_L0:
  iVar4 = 0xfe;
_L0:
  zdo_packet_free(auStack_50);
  return iVar4;
}

