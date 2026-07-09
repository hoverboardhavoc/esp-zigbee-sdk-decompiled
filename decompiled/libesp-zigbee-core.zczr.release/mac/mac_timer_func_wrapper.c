/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_timer_func_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void * mac_timer_func_wrapper(void *param_1)

{
  ushort uVar1;
  void *pvVar2;
  char cVar3;
  undefined1 *puVar4;
  int *piVar5;
  undefined4 uVar6;
  uint uVar7;
  int *extraout_a1;
  undefined2 uVar8;
  int iVar9;
  int iVar10;
  undefined2 uStack_50;
  undefined2 uStack_4e;
  undefined1 auStack_4c [36];
  undefined4 uStack_28;
  
  cVar3 = *(char *)((int)param_1 + 0x2e);
  if (cVar3 == '\x03') {
    *(undefined1 *)((int)param_1 + 0x2e) = 0;
    mac_start_op(5);
  }
  else {
    if (cVar3 != '\x06') {
      if (cVar3 == '\x01') goto mac_do_active_scan;
      piVar5 = (int *)__assert_func(0,0,0,0);
      iVar9 = *piVar5;
      pvVar2 = (void *)0x3;
      if ((((*(uint *)(iVar9 + 0x9c) & 1) != 0) && (pvVar2 = (void *)0x2, extraout_a1 != (int *)0x0)
          ) && (iVar10 = *extraout_a1, iVar10 != 0)) {
        uVar8 = *(undefined2 *)(iVar9 + 10);
        memset(auStack_4c,0,0x1c);
        uStack_4e = (undefined2)extraout_a1[6];
        uStack_50 = uVar8;
        uVar6 = mac_frame_write_hdr(auStack_4c,extraout_a1 + 1,&uStack_50,0,1,0);
        pvVar2 = (void *)zmsg_prepend_bytes(iVar10,uVar6,auStack_4c);
        if (pvVar2 == (void *)0x0) {
          uVar7 = zmsg_get_length(iVar10);
          if (uVar7 < 0x7e) {
            if ((*(byte *)((int)extraout_a1 + 0x1a) & 2) == 0) {
              zmsg_queue_enqueue(iVar9 + 0x48,iVar10);
              if ((*(char *)(iVar9 + 0x2e) != '\x04') && ((*(ushort *)(iVar9 + 0x30) & 0x10) == 0))
              {
                mac_start_op(iVar9);
              }
            }
            else {
              mac_indirect_transmit(iVar9,(int)extraout_a1 + 0xe,iVar10);
            }
          }
          else {
            pvVar2 = (void *)0x4;
          }
        }
      }
      return pvVar2;
    }
    *(undefined1 *)((int)param_1 + 0x2e) = 0;
    mac_report_poll_result_constprop_0(0xeb);
  }
  while( true ) {
    if ((*(uint *)((int)param_1 + 0x9c) & 1) == 0) {
      return param_1;
    }
    if (*(char *)((int)param_1 + 0x2e) != '\0') {
      return param_1;
    }
    uVar1 = *(ushort *)((int)param_1 + 0x30);
    if ((uVar1 & 0x40) == 0) {
      if ((uVar1 & 2) == 0) {
        if ((uVar1 & 4) == 0) {
          if ((uVar1 & 8) == 0) {
            if ((uVar1 & 0x80) == 0) {
              if ((uVar1 & 0x100) == 0) {
                if ((uVar1 & 0x20) == 0) {
                  uVar7 = 4;
                  if ((uVar1 & 0x10) == 0) {
                    if (*(char *)((int)param_1 + 0x2e) != '\0') {
                      return param_1;
                    }
                    if (-1 < *(int *)((int)param_1 + 0x28) << 0xe) {
                      pvVar2 = (void *)mac_pal_sleep();
                      return pvVar2;
                    }
                    pvVar2 = (void *)mac_pal_receive(*(undefined1 *)((int)param_1 + 0x42),
                                                     *(undefined1 *)((int)param_1 + 0x41));
                    return pvVar2;
                  }
                }
                else {
                  uVar7 = 5;
                }
              }
              else {
                uVar7 = 8;
              }
            }
            else {
              uVar7 = 7;
            }
          }
          else {
            uVar7 = 3;
          }
        }
        else {
          uVar7 = 2;
        }
      }
      else {
        uVar7 = 1;
      }
    }
    else {
      uVar7 = 6;
    }
    *(ushort *)((int)param_1 + 0x30) = uVar1 & ~(ushort)(1 << uVar7);
    *(char *)((int)param_1 + 0x2e) = (char)uVar7;
    pvVar2 = (void *)micro_timer_stop((int)param_1 + 0x8c);
    if (5 < uVar7) break;
    if (3 < uVar7) goto _L0;
    if (uVar7 == 2) {
      *(undefined1 *)((int)param_1 + 0x2d) = 1;
      pvVar2 = (void *)mac_do_ed_scan(param_1);
      return pvVar2;
    }
    if (uVar7 == 3) {
      *(undefined1 *)((int)param_1 + 0x2d) = 2;
      goto _L0;
    }
    *(undefined1 *)((int)param_1 + 0x2d) = 1;
mac_do_active_scan:
    if (((*(uint *)((int)param_1 + 0x9c) & 1) != 0) &&
       (iVar9 = mac_update_scan_channel_part_0(), iVar9 == 0)) goto mac_do_transmit_part_0;
    mac_pal_set_panid(*(undefined2 *)((int)param_1 + 10));
    mac_pal_set_rx_when_idle(*(uint *)((int)param_1 + 0x28) >> 0x11 & 1);
    *(undefined1 *)((int)param_1 + 0x2d) = 0;
    *(undefined1 *)((int)param_1 + 0x2e) = 0;
    if (*(code **)((int)param_1 + 0x38) != (code *)0x0) {
      (**(code **)((int)param_1 + 0x38))(0,*(undefined4 *)((int)param_1 + 0x3c));
    }
  }
  if (uVar7 == 6) {
    mac_pal_receive(*(undefined1 *)((int)param_1 + 0x42),*(undefined1 *)((int)param_1 + 0x41));
    pvVar2 = (void *)micro_timer_start((int)param_1 + 0x8c,
                                       ((*(ushort *)((int)param_1 + 0x1c) + 0x3bf) / 0x3c0 + 1) *
                                       0x3c00);
    return pvVar2;
  }
_L0:
  if ((*(uint *)((int)param_1 + 0x9c) & 1) == 0) {
    return pvVar2;
  }
mac_do_transmit_part_0:
  piVar5 = (int *)mac_pal_get_tx_frame();
  *(undefined1 *)((int)piVar5 + 5) = *(undefined1 *)((int)param_1 + 0x41);
  *(undefined1 *)(piVar5 + 4) = *(undefined1 *)((int)param_1 + 0x1e);
  *(undefined1 *)((int)piVar5 + 0x11) = *(undefined1 *)((int)param_1 + 0x22);
  *(undefined1 *)((int)piVar5 + 0x12) = *(undefined1 *)((int)param_1 + 0x21);
  *(undefined1 *)((int)piVar5 + 0x13) = *(undefined1 *)((int)param_1 + 0x20);
  uVar7 = (uint)*(byte *)((int)param_1 + 0x2e);
  if (uVar7 == 5) {
    mac_pal_set_rx_when_idle(1);
    uVar7 = 3;
    memcpy(&stack0xffffffde,param_1,8);
    uStack_28 = CONCAT22(*(undefined2 *)((int)param_1 + 10),*(undefined2 *)((int)param_1 + 10));
    cVar3 = mac_frame_write_hdr(*piVar5,&stack0xffffffdc,&uStack_28,0,3,4);
    *(char *)(piVar5 + 1) = cVar3 + '\x02';
    goto _L0;
  }
  if (5 < uVar7) goto _L0;
  if (uVar7 == 3) {
    memcpy(&stack0xffffffde,param_1,8);
    uStack_28 = CONCAT22(*(undefined2 *)((int)param_1 + 10),0xffff);
    cVar3 = mac_frame_write_hdr(*piVar5,&stack0xffffffdc,&uStack_28,0,3,1);
    *(char *)(piVar5 + 1) = cVar3 + '\x02';
    *(char *)((int)param_1 + 0xc) = *(char *)((int)param_1 + 0xc) + '\x01';
    mac_frame_set_seq_num(piVar5);
    iVar10 = *piVar5;
    iVar9 = mac_frame_find_payload_index(piVar5);
    uVar7 = iVar10 + iVar9;
    *(undefined1 *)(uVar7 + 1) = *(undefined1 *)((int)param_1 + 0x40);
    *(char *)(piVar5 + 1) = (char)piVar5[1] + '\x01';
    goto _L0;
  }
  if (uVar7 == 4) {
    iVar9 = (int)param_1 + 0x48;
    goto _L0;
  }
  if (uVar7 == 1) {
    uStack_28 = 0xffffffff;
    cVar3 = mac_frame_write_hdr(*piVar5,&stack0xffffffdc,&uStack_28,0,7);
    *(char *)(piVar5 + 1) = cVar3 + '\x02';
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
    if (uVar7 == 7) {
      memset(&stack0xffffffdd,0,0x13);
      uStack_28 = CONCAT22(0xffff,*(undefined2 *)((int)param_1 + 10));
      cVar3 = mac_frame_write_hdr(*piVar5,&stack0xffffffdc,&uStack_28,0,0,0);
      *(char *)(piVar5 + 1) = cVar3 + '\x02';
      *(char *)((int)param_1 + 0xd) = *(char *)((int)param_1 + 0xd) + '\x01';
      mac_frame_set_seq_num(piVar5);
      iVar10 = *piVar5;
      iVar9 = mac_frame_find_payload_index(piVar5);
      uVar1 = *(ushort *)((int)param_1 + 0x2a);
      puVar4 = (undefined1 *)(iVar9 + iVar10);
      if ((*(short *)((int)param_1 + 0xe) == -1) ||
         (uVar8 = 0x4fff, *(short *)((int)param_1 + 8) != *(short *)((int)param_1 + 0xe))) {
        uVar8 = 0xfff;
      }
      *puVar4 = (char)uVar8;
      puVar4[2] = 0;
      puVar4[3] = 0;
      puVar4[1] = (byte)(((uVar1 & 1) << 0xf) >> 8) | (byte)((ushort)uVar8 >> 8);
      uVar7 = 0;
      *(char *)(piVar5 + 1) = (char)piVar5[1] + '\x04';
      if ((*(void **)((int)param_1 + 0x24) != (void *)0x0) &&
         (uVar7 = (uint)*(byte *)((int)param_1 + 0x23), uVar7 != 0)) {
        memcpy(puVar4 + 4,*(void **)((int)param_1 + 0x24),uVar7);
      }
      uVar7 = uVar7 + *(byte *)(piVar5 + 1);
      *(char *)(piVar5 + 1) = (char)uVar7;
    }
    else {
      iVar9 = (int)param_1 + 0x54;
      if (uVar7 != 8) goto _L0;
_L0:
      iVar9 = zmsg_queue_get_head(iVar9);
      if (iVar9 == 0) goto _L0;
      txframe_from_zmsg_isra_0(piVar5);
_L0:
      *(char *)((int)param_1 + 0xc) = *(char *)((int)param_1 + 0xc) + '\x01';
      mac_frame_set_seq_num(piVar5);
    }
_L0:
    iVar9 = mac_pal_transmit();
    if (iVar9 == 0) {
      return (void *)0x0;
    }
  } while( true );
}

