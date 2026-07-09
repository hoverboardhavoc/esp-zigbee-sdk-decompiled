/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_send_ack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int aps_send_ack(undefined2 *param_1,int param_2,undefined1 param_3,undefined1 param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined2 uStack_40;
  int aiStack_3c [7];
  
  iVar2 = zmsg_alloc(0x2f);
  if (iVar2 == 0) {
_L0:
    iVar3 = 1;
  }
  else {
    uVar4 = (uint)*(byte *)(param_1 + 6);
    if ((*(byte *)(param_1 + 6) & 3) == 0) {
_L0:
      bVar1 = 2;
    }
    else {
      if ((uVar4 & 3) != 1) {
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_main.c",0x92,
                      "aps_send_ack",&_LC2);
        goto _L0;
      }
      bVar1 = 0x12;
    }
    bVar5 = bVar1 | (byte)uVar4 & 0xa0;
    uStack_4c = CONCAT31(uStack_4c._1_3_,bVar5);
    zmsg_append_bytes(iVar2,1,&uStack_4c);
    if (((bVar1 & 2) != 1) && (((bVar1 & 2) == 0 || ((bVar1 & 0x10) == 0)))) {
      uStack_4c._0_2_ = CONCAT11((char)param_1[4],*(undefined1 *)(param_1 + 3));
      uStack_4c._0_3_ = CONCAT12((char)((ushort)param_1[4] >> 8),(undefined2)uStack_4c);
      uStack_4c = CONCAT13((char)param_1[5],(undefined3)uStack_4c);
      uStack_48 = CONCAT31(CONCAT21((short)((uint)uStack_48 >> 0x10),
                                    *(undefined1 *)((int)param_1 + 7)),
                           (char)((ushort)param_1[5] >> 8));
      zmsg_append_bytes(iVar2,6,&uStack_4c);
    }
    uStack_4c = CONCAT31(uStack_4c._1_3_,*(undefined1 *)((int)param_1 + 0xd));
    zmsg_append_bytes(iVar2,1,&uStack_4c);
    if ((char)bVar5 < '\0') {
      bVar5 = uStack_4c._3_1_;
      uStack_4c = (uint)uStack_4c._3_1_ << 0x18;
      bVar1 = *(byte *)((int)param_1 + 0x11);
      uStack_4c = CONCAT31(uStack_4c._1_3_,bVar1);
      if (((bVar1 & 3) == 1) || ((bVar1 & 3) == 2)) {
        uStack_4c._0_2_ = CONCAT11(param_3,bVar1);
        uStack_4c._0_3_ = CONCAT12(param_4,(undefined2)uStack_4c);
        uStack_4c = CONCAT13(bVar5,(undefined3)uStack_4c);
        zmsg_append_bytes(iVar2,3,&uStack_4c);
      }
      else {
        local_50 = CONCAT31(local_50._1_3_,bVar1);
        zmsg_append_bytes(iVar2,1,&local_50);
      }
    }
    if ((uVar4 & 0x20) != 0) {
      if ((*(ushort *)(param_2 + 0x16) & 4) == 0) {
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_main.c",0xb6,
                      "aps_send_ack",
                      "zmsg_test_flag(rx_msg, ((1 << ((2) % (sizeof(unsigned long) * 8)))))");
        goto _L0;
      }
      uStack_4c = 0;
      uStack_48 = 0;
      uStack_44 = 0;
      uStack_40 = 0;
      zmsg_append_bytes(iVar2,5,&uStack_4c);
      zmsg_get_footer(param_2,&local_50,4);
      iVar3 = aps_process_transmit_security_by_key_pair(local_50,iVar2);
      if (iVar3 != 0) goto _L0;
    }
    aiStack_3c[1] = 0;
    aiStack_3c[2] = 0;
    aiStack_3c[3] = 0;
    aiStack_3c[4] = 0;
    aiStack_3c[5] = 0;
    aiStack_3c[6] = 0;
    aiStack_3c[0] = iVar2;
    iVar3 = aps_send_frame(*param_1,aiStack_3c);
    if (iVar3 == 0) {
      return 0;
    }
  }
_L0:
  if (iVar2 != 0) {
    zmsg_free(iVar2);
  }
  return iVar3;
}

