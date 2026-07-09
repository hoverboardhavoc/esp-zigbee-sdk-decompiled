/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> aps_send_ack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int aps_send_ack(undefined2 *param_1,int param_2,undefined1 param_3,undefined1 param_4)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  byte bVar7;
  byte bVar8;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined2 uStack_30;
  
  iVar2 = zmsg_alloc(0x2f);
  if (iVar2 == 0) {
    iVar3 = 1;
  }
  else {
    uVar6 = (uint)*(byte *)(param_1 + 6);
    if ((*(byte *)(param_1 + 6) & 3) == 0) goto _L0;
    bVar7 = 0x12;
    if ((uVar6 & 3) == 1) goto _L0;
    do {
      __assert_func(0,0,0,0);
_L0:
      bVar7 = 2;
_L0:
      bVar8 = bVar7 | (byte)uVar6 & 0xa0;
      uStack_3c = CONCAT31(uStack_3c._1_3_,bVar8);
      zmsg_append_bytes(iVar2,1,&uStack_3c);
      if ((bVar7 & 0x10) == 0) {
        uStack_3c._0_2_ = CONCAT11((char)param_1[4],*(undefined1 *)(param_1 + 3));
        uStack_3c._0_3_ = CONCAT12((char)((ushort)param_1[4] >> 8),(undefined2)uStack_3c);
        uStack_3c = CONCAT13((char)param_1[5],(undefined3)uStack_3c);
        uStack_38 = CONCAT31(CONCAT21(uStack_38._2_2_,*(undefined1 *)((int)param_1 + 7)),
                             (char)((ushort)param_1[5] >> 8));
        zmsg_append_bytes(iVar2,6,&uStack_3c);
      }
      uStack_3c = CONCAT31(uStack_3c._1_3_,*(undefined1 *)((int)param_1 + 0xd));
      zmsg_append_bytes(iVar2,1,&uStack_3c);
      if ((char)bVar8 < '\0') {
        bVar7 = *(byte *)((int)param_1 + 0x11);
        bVar8 = uStack_3c._3_1_;
        uStack_3c = (uint)uStack_3c._3_1_ << 0x18;
        uStack_3c = CONCAT31(uStack_3c._1_3_,bVar7);
        uVar4 = 1;
        if ((byte)((bVar7 & 3) - 1) < 2) {
          uStack_3c._0_2_ = CONCAT11(param_3,bVar7);
          uStack_3c._0_3_ = CONCAT12(param_4,(undefined2)uStack_3c);
          uStack_3c = CONCAT13(bVar8,(undefined3)uStack_3c);
          uVar4 = 3;
          puVar5 = &uStack_3c;
        }
        else {
          local_40 = CONCAT31(local_40._1_3_,bVar7);
          puVar5 = &local_40;
        }
        zmsg_append_bytes(iVar2,uVar4,puVar5);
      }
      if ((uVar6 & 0x20) == 0) goto _L0;
      uVar6 = 0;
    } while ((*(ushort *)(param_2 + 0x16) & 4) == 0);
    uStack_3c = 0;
    uStack_38 = 0;
    uStack_34 = 0;
    uStack_30 = 0;
    zmsg_append_bytes(iVar2,5,&uStack_3c);
    zmsg_get_footer(param_2,&local_40,4);
    iVar3 = aps_process_transmit_security_by_key_pair(local_40,iVar2);
    if (iVar3 == 0) {
_L0:
      uVar1 = *param_1;
      memset(&uStack_38,0,0x18);
      uStack_3c = iVar2;
      iVar3 = aps_send_frame(uVar1,&uStack_3c);
      if (iVar3 == 0) {
        return 0;
      }
    }
    zmsg_free(iVar2);
  }
  return iVar3;
}

