/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_do_ed_scan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_do_ed_scan(void *param_1)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  char cVar4;
  int *piVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined2 uVar8;
  int iVar9;
  uint uVar10;
  uint unaff_s3;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint uStack_14;
  
  if (((*(uint *)((int)param_1 + 0x9c) & 1) != 0) &&
     (iVar7 = mac_update_scan_channel_part_0(), iVar7 == 0)) {
    bVar1 = *(byte *)((int)param_1 + 0x33);
    uVar10 = *(uint *)((int)param_1 + 0x34) >> 0x1b;
    uVar3 = (uint)*(byte *)((int)param_1 + 0x32);
    if (-1 < *(int *)((int)param_1 + 0x28) << 0xe) {
      uStack_14 = (uint)*(byte *)((int)param_1 + 0x32);
      mac_pal_receive(uVar10);
      uVar3 = uStack_14;
    }
    iVar7 = mac_pal_energy_detect
                      (uVar10,uVar3,(uint)(((1 << (bVar1 & 0x1f)) + 1) * 0x3c00) / 1000 & 0xffff);
    if (iVar7 == 0) {
      return;
    }
  }
  *(undefined1 *)((int)param_1 + 0x2e) = 0;
  *(undefined1 *)((int)param_1 + 0x2d) = 0;
  if (*(code **)((int)param_1 + 0x38) != (code *)0x0) {
    (**(code **)((int)param_1 + 0x38))(0,*(undefined4 *)((int)param_1 + 0x3c));
  }
  while( true ) {
    if ((*(uint *)((int)param_1 + 0x9c) & 1) == 0) {
      return;
    }
    if (*(char *)((int)param_1 + 0x2e) != '\0') {
      return;
    }
    uVar2 = *(ushort *)((int)param_1 + 0x30);
    if ((uVar2 & 0x40) == 0) {
      if ((uVar2 & 2) == 0) {
        if ((uVar2 & 4) == 0) {
          if ((uVar2 & 8) == 0) {
            if ((uVar2 & 0x80) == 0) {
              if ((uVar2 & 0x100) == 0) {
                if ((uVar2 & 0x20) == 0) {
                  uVar3 = 4;
                  if ((uVar2 & 0x10) == 0) {
                    if (*(char *)((int)param_1 + 0x2e) != '\0') {
                      return;
                    }
                    if (-1 < *(int *)((int)param_1 + 0x28) << 0xe) {
                      mac_pal_sleep();
                      return;
                    }
                    mac_pal_receive(*(undefined1 *)((int)param_1 + 0x42),
                                    *(undefined1 *)((int)param_1 + 0x41));
                    return;
                  }
                }
                else {
                  uVar3 = 5;
                }
              }
              else {
                uVar3 = 8;
              }
            }
            else {
              uVar3 = 7;
            }
          }
          else {
            uVar3 = 3;
          }
        }
        else {
          uVar3 = 2;
        }
      }
      else {
        uVar3 = 1;
      }
    }
    else {
      uVar3 = 6;
    }
    *(ushort *)((int)param_1 + 0x30) = uVar2 & ~(ushort)(1 << uVar3);
    *(char *)((int)param_1 + 0x2e) = (char)uVar3;
    uStack_14 = unaff_s3;
    micro_timer_stop((int)param_1 + 0x8c);
    unaff_s3 = uStack_14;
    if (5 < uVar3) break;
    if (3 < uVar3) goto _L0;
    if (uVar3 == 2) {
      *(undefined1 *)((int)param_1 + 0x2d) = 1;
      mac_do_ed_scan(param_1);
      return;
    }
    if (uVar3 == 3) {
      *(undefined1 *)((int)param_1 + 0x2d) = 2;
      goto _L0;
    }
    *(undefined1 *)((int)param_1 + 0x2d) = 1;
    if (((*(uint *)((int)param_1 + 0x9c) & 1) != 0) &&
       (iVar7 = mac_update_scan_channel_part_0(), iVar7 == 0)) goto mac_do_transmit_part_0;
    mac_pal_set_panid(*(undefined2 *)((int)param_1 + 10));
    mac_pal_set_rx_when_idle(*(uint *)((int)param_1 + 0x28) >> 0x11 & 1);
    *(undefined1 *)((int)param_1 + 0x2d) = 0;
    *(undefined1 *)((int)param_1 + 0x2e) = 0;
    if (*(code **)((int)param_1 + 0x38) != (code *)0x0) {
      (**(code **)((int)param_1 + 0x38))(0,*(undefined4 *)((int)param_1 + 0x3c));
    }
  }
  if (uVar3 == 6) {
    mac_pal_receive(*(undefined1 *)((int)param_1 + 0x42),*(undefined1 *)((int)param_1 + 0x41));
    micro_timer_start((int)param_1 + 0x8c,
                      ((*(ushort *)((int)param_1 + 0x1c) + 0x3bf) / 0x3c0 + 1) * 0x3c00);
    return;
  }
_L0:
  if ((*(uint *)((int)param_1 + 0x9c) & 1) == 0) {
    return;
  }
mac_do_transmit_part_0:
  piVar5 = (int *)mac_pal_get_tx_frame();
  *(undefined1 *)((int)piVar5 + 5) = *(undefined1 *)((int)param_1 + 0x41);
  *(undefined1 *)(piVar5 + 4) = *(undefined1 *)((int)param_1 + 0x1e);
  *(undefined1 *)((int)piVar5 + 0x11) = *(undefined1 *)((int)param_1 + 0x22);
  *(undefined1 *)((int)piVar5 + 0x12) = *(undefined1 *)((int)param_1 + 0x21);
  *(undefined1 *)((int)piVar5 + 0x13) = *(undefined1 *)((int)param_1 + 0x20);
  bVar1 = *(byte *)((int)param_1 + 0x2e);
  uVar3 = (uint)bVar1;
  if (uVar3 == 5) {
    mac_pal_set_rx_when_idle(1);
    uVar3 = 3;
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
    cVar4 = mac_frame_write_hdr(*piVar5,&uStack_24,&uStack_28,0,3,4);
    *(char *)(piVar5 + 1) = cVar4 + '\x02';
    goto _L0;
  }
  if (5 < uVar3) goto _L0;
  if (uVar3 == 3) {
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
    cVar4 = mac_frame_write_hdr(*piVar5,&uStack_24,&uStack_28,0,3,1);
    *(char *)(piVar5 + 1) = cVar4 + '\x02';
    *(char *)((int)param_1 + 0xc) = *(char *)((int)param_1 + 0xc) + '\x01';
    mac_frame_set_seq_num(piVar5);
    iVar9 = *piVar5;
    iVar7 = mac_frame_find_payload_index(piVar5);
    uVar3 = iVar9 + iVar7;
    *(undefined1 *)(uVar3 + 1) = *(undefined1 *)((int)param_1 + 0x40);
    *(char *)(piVar5 + 1) = (char)piVar5[1] + '\x01';
    goto _L0;
  }
  if (uVar3 == 4) {
    iVar7 = (int)param_1 + 0x48;
    goto _L0;
  }
  if (uVar3 == 1) {
    uStack_1c = 0x20000;
    uStack_18 = 0xffff;
    uStack_28 = 0xffffffff;
    uStack_24 = 0;
    uStack_20 = 0;
    uStack_14 = 0;
    cVar4 = mac_frame_write_hdr(*piVar5,&uStack_24,&uStack_28,0,7);
    *(char *)(piVar5 + 1) = cVar4 + '\x02';
    *(char *)((int)param_1 + 0xc) = *(char *)((int)param_1 + 0xc) + '\x01';
    mac_frame_set_seq_num(piVar5);
    mac_pal_set_panid(0xffff);
    mac_pal_set_rx_when_idle(1);
    *(undefined1 *)((int)piVar5 + 5) = *(undefined1 *)((int)param_1 + 0x32);
    goto _L0;
  }
_L0:
  do {
    __assert_func(0,0,0,0);
_L0:
    if (uVar3 == 7) {
      memset((void *)((int)&uStack_24 + 1),0,0x13);
      uStack_24 = CONCAT31(uStack_24._1_3_,2);
      uStack_24 = CONCAT22(*(undefined2 *)((int)param_1 + 8),(undefined2)uStack_24);
      uStack_28 = CONCAT22(0xffff,*(undefined2 *)((int)param_1 + 10));
      cVar4 = mac_frame_write_hdr(*piVar5,&uStack_24,&uStack_28,0,0,0);
      *(char *)(piVar5 + 1) = cVar4 + '\x02';
      *(char *)((int)param_1 + 0xd) = *(char *)((int)param_1 + 0xd) + '\x01';
      mac_frame_set_seq_num(piVar5);
      iVar9 = *piVar5;
      iVar7 = mac_frame_find_payload_index(piVar5);
      uVar2 = *(ushort *)((int)param_1 + 0x2a);
      puVar6 = (undefined1 *)(iVar7 + iVar9);
      if ((*(short *)((int)param_1 + 0xe) == -1) ||
         (uVar8 = 0x4fff, *(short *)((int)param_1 + 8) != *(short *)((int)param_1 + 0xe))) {
        uVar8 = 0xfff;
      }
      *puVar6 = (char)uVar8;
      puVar6[2] = 0;
      puVar6[3] = 0;
      puVar6[1] = (byte)(((uVar2 & 1) << 0xf) >> 8) | (byte)((ushort)uVar8 >> 8);
      uVar3 = 0;
      *(char *)(piVar5 + 1) = (char)piVar5[1] + '\x04';
      if ((*(void **)((int)param_1 + 0x24) != (void *)0x0) &&
         (uVar3 = (uint)*(byte *)((int)param_1 + 0x23), uVar3 != 0)) {
        memcpy(puVar6 + 4,*(void **)((int)param_1 + 0x24),uVar3);
      }
      uVar3 = uVar3 + *(byte *)(piVar5 + 1);
      *(char *)(piVar5 + 1) = (char)uVar3;
    }
    else {
      iVar7 = (int)param_1 + 0x54;
      if (uVar3 != 8) goto _L0;
_L0:
      iVar7 = zmsg_queue_get_head(iVar7);
      if (iVar7 == 0) goto _L0;
      txframe_from_zmsg_isra_0(piVar5);
_L0:
      *(char *)((int)param_1 + 0xc) = *(char *)((int)param_1 + 0xc) + '\x01';
      mac_frame_set_seq_num(piVar5);
    }
_L0:
    iVar7 = mac_pal_transmit();
    if (iVar7 == 0) {
      return;
    }
  } while( true );
}

