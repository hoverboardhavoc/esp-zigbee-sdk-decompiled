/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_do_transmit.part.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_do_transmit_part_0(void *param_1)

{
  byte bVar1;
  ushort uVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined2 uVar7;
  uint uVar8;
  int iVar9;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  piVar4 = (int *)mac_pal_get_tx_frame();
  *(undefined1 *)((int)piVar4 + 5) = *(undefined1 *)((int)param_1 + 0x41);
  *(undefined1 *)(piVar4 + 4) = *(undefined1 *)((int)param_1 + 0x1e);
  *(undefined1 *)((int)piVar4 + 0x11) = *(undefined1 *)((int)param_1 + 0x22);
  *(undefined1 *)((int)piVar4 + 0x12) = *(undefined1 *)((int)param_1 + 0x21);
  *(undefined1 *)((int)piVar4 + 0x13) = *(undefined1 *)((int)param_1 + 0x20);
  bVar1 = *(byte *)((int)param_1 + 0x2e);
  uVar8 = (uint)bVar1;
  if (uVar8 == 5) {
    mac_pal_set_rx_when_idle(1);
    uVar8 = 3;
    uStack_24 = CONCAT31(uStack_24._1_3_,3);
    memcpy((void *)((int)&uStack_24 + 2),param_1,8);
    uStack_18 = *(undefined4 *)((int)param_1 + 0x10);
    uStack_1c._0_3_ = CONCAT12(3,(undefined2)uStack_1c);
    uStack_14 = *(undefined4 *)((int)param_1 + 0x14);
    uStack_28 = CONCAT22(*(undefined2 *)((int)param_1 + 10),*(undefined2 *)((int)param_1 + 10));
    if (*(ushort *)((int)param_1 + 0xe) < 0xfffe) {
      uStack_1c._0_3_ = CONCAT12(2,(undefined2)uStack_1c);
      uStack_18._2_2_ = (undefined2)((uint)uStack_18 >> 0x10);
      uStack_18 = CONCAT22(uStack_18._2_2_,*(ushort *)((int)param_1 + 0xe));
    }
    if (*(ushort *)((int)param_1 + 8) < 0xfffe) {
      uStack_24 = CONCAT31(uStack_24._1_3_,2);
      uStack_24 = CONCAT22(*(ushort *)((int)param_1 + 8),(undefined2)uStack_24);
    }
    cVar3 = mac_frame_write_hdr(*piVar4,&uStack_24,&uStack_28,0,3,4);
    *(char *)(piVar4 + 1) = cVar3 + '\x02';
    goto _L0;
  }
  if (5 < uVar8) goto _L0;
  if (uVar8 == 3) {
    uStack_24 = CONCAT31(uStack_24._1_3_,bVar1);
    memcpy((void *)((int)&uStack_24 + 2),param_1,8);
    uStack_18 = *(undefined4 *)((int)param_1 + 0x10);
    uStack_1c._0_3_ = CONCAT12(bVar1,(undefined2)uStack_1c);
    uStack_14 = *(undefined4 *)((int)param_1 + 0x14);
    uStack_28 = CONCAT22(*(undefined2 *)((int)param_1 + 10),0xffff);
    if (*(ushort *)((int)param_1 + 0xe) < 0xfffe) {
      uStack_1c._0_3_ = CONCAT12(2,(undefined2)uStack_1c);
      uStack_18._2_2_ = (undefined2)((uint)uStack_18 >> 0x10);
      uStack_18 = CONCAT22(uStack_18._2_2_,*(ushort *)((int)param_1 + 0xe));
    }
    cVar3 = mac_frame_write_hdr(*piVar4,&uStack_24,&uStack_28,0,3,1);
    *(char *)(piVar4 + 1) = cVar3 + '\x02';
    *(char *)((int)param_1 + 0xc) = *(char *)((int)param_1 + 0xc) + '\x01';
    mac_frame_set_seq_num(piVar4);
    iVar9 = *piVar4;
    iVar5 = mac_frame_find_payload_index(piVar4);
    uVar8 = iVar9 + iVar5;
    *(undefined1 *)(uVar8 + 1) = *(undefined1 *)((int)param_1 + 0x40);
    *(char *)(piVar4 + 1) = (char)piVar4[1] + '\x01';
    goto _L0;
  }
  if (uVar8 == 4) {
    iVar5 = (int)param_1 + 0x48;
    goto _L0;
  }
  if (uVar8 == 1) {
    uStack_1c = 0x20000;
    uStack_18 = 0xffff;
    uStack_28 = 0xffffffff;
    uStack_24 = 0;
    uStack_20 = 0;
    uStack_14 = 0;
    cVar3 = mac_frame_write_hdr(*piVar4,&uStack_24,&uStack_28,0,7);
    *(char *)(piVar4 + 1) = cVar3 + '\x02';
    *(char *)((int)param_1 + 0xc) = *(char *)((int)param_1 + 0xc) + '\x01';
    mac_frame_set_seq_num(piVar4);
    mac_pal_set_panid(0xffff);
    mac_pal_set_rx_when_idle(1);
    *(undefined1 *)((int)piVar4 + 5) = *(undefined1 *)((int)param_1 + 0x32);
    goto _L0;
  }
_L0:
  do {
    __assert_func(0,0,0,0);
_L0:
    if (uVar8 == 7) {
      memset((void *)((int)&uStack_24 + 1),0,0x13);
      uStack_24 = CONCAT31(uStack_24._1_3_,2);
      uStack_24 = CONCAT22(*(undefined2 *)((int)param_1 + 8),(undefined2)uStack_24);
      uStack_28 = CONCAT22(0xffff,*(undefined2 *)((int)param_1 + 10));
      cVar3 = mac_frame_write_hdr(*piVar4,&uStack_24,&uStack_28,0,0,0);
      *(char *)(piVar4 + 1) = cVar3 + '\x02';
      *(char *)((int)param_1 + 0xd) = *(char *)((int)param_1 + 0xd) + '\x01';
      mac_frame_set_seq_num(piVar4);
      iVar9 = *piVar4;
      iVar5 = mac_frame_find_payload_index(piVar4);
      uVar2 = *(ushort *)((int)param_1 + 0x2a);
      puVar6 = (undefined1 *)(iVar5 + iVar9);
      if ((*(short *)((int)param_1 + 0xe) == -1) ||
         (uVar7 = 0x4fff, *(short *)((int)param_1 + 8) != *(short *)((int)param_1 + 0xe))) {
        uVar7 = 0xfff;
      }
      *puVar6 = (char)uVar7;
      puVar6[2] = 0;
      puVar6[3] = 0;
      puVar6[1] = (byte)(((uVar2 & 1) << 0xf) >> 8) | (byte)((ushort)uVar7 >> 8);
      uVar8 = 0;
      *(char *)(piVar4 + 1) = (char)piVar4[1] + '\x04';
      if ((*(void **)((int)param_1 + 0x24) != (void *)0x0) &&
         (uVar8 = (uint)*(byte *)((int)param_1 + 0x23), uVar8 != 0)) {
        memcpy(puVar6 + 4,*(void **)((int)param_1 + 0x24),uVar8);
      }
      uVar8 = uVar8 + *(byte *)(piVar4 + 1);
      *(char *)(piVar4 + 1) = (char)uVar8;
    }
    else {
      iVar5 = (int)param_1 + 0x54;
      if (uVar8 != 8) goto _L0;
_L0:
      iVar5 = zmsg_queue_get_head(iVar5);
      if (iVar5 == 0) goto _L0;
      txframe_from_zmsg_isra_0(piVar4);
_L0:
      *(char *)((int)param_1 + 0xc) = *(char *)((int)param_1 + 0xc) + '\x01';
      mac_frame_set_seq_num(piVar4);
    }
_L0:
    iVar5 = mac_pal_transmit();
    if (iVar5 == 0) {
      return;
    }
  } while( true );
}

