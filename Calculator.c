#if(0)
#include <gtk/gtk.h>

int main (int argc,char *argv[])

{
        GtkWidget *windows;
        gtk_init(&argc,&argv);                         //初始化GTK程序
        windows = gtk_window_new(GTK_WINDOW_TOPLEVEL); //创建一个窗口
        gtk_widget_show(windows);                      //显示窗口
        gtk_main();                                    //GTK必不可少的函数
        return 0;
}
#endif

#if(0)
#include <gtk/gtk.h>

int main (int argc,char *argv[])

{
        GtkWidget *windows;
        gtk_init(&argc,&argv);  //初始化GTK程序

        windows = gtk_window_new(GTK_WINDOW_TOPLEVEL);  //创建一个窗口（TOP顶层）
        gtk_window_set_title(GTK_WINDOW(windows),"计算器");  //设置窗口标题

        GtkWidget *a = gtk_table_new(5,4,TRUE);  //布局容器的创建(选择布局方式:水平,垂直,表格,固定)
        gtk_container_add(GTK_CONTAINER(windows),a);  //将容器添加到窗口里

        GtkWidget *b1 = gtk_button_new_with_label("Hello world!");  //按钮的创建
        gtk_fixed_put(GTK_FIXED(a),b1,0,0);  //容器的添加（注意使用不同的布局方式会用不同的写法）

        GtkWidget *b2 = gtk_button_new_with_label("Hello GTK!");  //按钮的创建
        gtk_fixed_put(GTK_FIXED(a),b2,50,50);  //容器的添加（容器即窗口和按钮）

        GtkWidget *b3 = gtk_button_new_with_label("Hello li!");  //按钮的创建
        gtk_fixed_put(GTK_FIXED(a),b3,0,0);  //容器的添加（容器即窗口和按钮）

        gtk_fixed_move(GTK_FIXED(a),b3,100,100);  //将b3移动到(100,100)
        gtk_widget_set_size_request(b3,100,50);  //设置b3的大小

        gtk_widget_show_all(windows);  //显示窗口
        gtk_main();                    //GTK必不可少的函数

        return 0;
}
#endif

#if(0)
/*计算器界面显示，静态*/

#include <gtk/gtk.h>

int main(int argc,char *argv[])
{
        gtk_init(&argc,&argv);

        GtkWidget *w;
        w = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(w),"计算器");

        GtkWidget *a = gtk_table_new(5,4,TRUE);
        gtk_container_add(GTK_CONTAINER(w),a);

        GtkWidget *h = gtk_entry_new();
        gtk_entry_set_text(GTK_ENTRY(h),"2+2=4");
        gtk_editable_set_editable(GTK_EDITABLE(h),FALSE);

        GtkWidget *b0 = gtk_button_new_with_label("0");
        GtkWidget *b1 = gtk_button_new_with_label("1");
        GtkWidget *b2 = gtk_button_new_with_label("2");
        GtkWidget *b3 = gtk_button_new_with_label("3");
        GtkWidget *b4 = gtk_button_new_with_label("4");
        GtkWidget *b5 = gtk_button_new_with_label("5");
        GtkWidget *b6 = gtk_button_new_with_label("6");
        GtkWidget *b7 = gtk_button_new_with_label("7");
        GtkWidget *b8 = gtk_button_new_with_label("8");
        GtkWidget *b9 = gtk_button_new_with_label("9");

        GtkWidget *b_add = gtk_button_new_with_label("+");
        GtkWidget *b_minus = gtk_button_new_with_label("-");
        GtkWidget *b_mul = gtk_button_new_with_label("*");
        GtkWidget *b_div = gtk_button_new_with_label("/");
        GtkWidget *b_equal = gtk_button_new_with_label("=");
        GtkWidget *b_del = gtk_button_new_with_label("c");

        gtk_table_attach_defaults(GTK_TABLE(a),h,0,4,0,1);

        gtk_table_attach_defaults(GTK_TABLE(a),b0,0,1,4,5);
        gtk_table_attach_defaults(GTK_TABLE(a),b1,0,1,3,4);
        gtk_table_attach_defaults(GTK_TABLE(a),b2,1,2,3,4);
        gtk_table_attach_defaults(GTK_TABLE(a),b3,2,3,3,4);
        gtk_table_attach_defaults(GTK_TABLE(a),b4,0,1,2,3);
        gtk_table_attach_defaults(GTK_TABLE(a),b5,1,2,2,3);
        gtk_table_attach_defaults(GTK_TABLE(a),b6,2,3,2,3);
        gtk_table_attach_defaults(GTK_TABLE(a),b7,0,1,1,2);
        gtk_table_attach_defaults(GTK_TABLE(a),b8,1,2,1,2);
        gtk_table_attach_defaults(GTK_TABLE(a),b9,2,3,1,2);

        gtk_table_attach_defaults(GTK_TABLE(a),b_add,1,2,4,5);
        gtk_table_attach_defaults(GTK_TABLE(a),b_minus,2,3,4,5);
        gtk_table_attach_defaults(GTK_TABLE(a),b_mul,3,4,2,3);
        gtk_table_attach_defaults(GTK_TABLE(a),b_div,3,4,3,4);
        gtk_table_attach_defaults(GTK_TABLE(a),b_equal,3,4,4,5);
        gtk_table_attach_defaults(GTK_TABLE(a),b_del,3,4,1,2);

        gtk_widget_show_all(w);

        gtk_main();

        return 0;
}
#endif                                                                                                                                                   

#if(0)
/*按键一次显示一次Hello,GTK!*/

#include <gtk/gtk.h>
#include <stdio.h>

void d(GtkButton *b,gpointer user_data)
{
        const char *t = gtk_button_get_label(b);

        printf("%s----%s\n",(char *)user_data,t);

        return;
}

int main(int argc,char *argv[])

{
        gtk_init(&argc,&argv);

        GtkWidget *w;
        w = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_container_set_border_width(GTK_CONTAINER(w),15);

        GtkWidget *b = gtk_button_new_with_label(" ");
        gtk_container_add(GTK_CONTAINER(w),b);

        GtkWidget *b = gtk_button_new_with_label(" ");
        gtk_container_add(GTK_CONTAINER(w),b);

        g_signal_connect(b,"pressed",G_CALLBACK( d ),"Hello,GTK!");

        gtk_widget_show_all(w);

        gtk_main();

        return 0;
}
#endif

#if(1)
/*计算器（实现加减乘除）*/
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

char buf[50] = "";

void deal_num(GtkButton *b,gpointer data)
{
        const char *t = gtk_button_get_label(b);

        if (0  == strcmp(t,"c"))
        {
                buf[strlen(buf)-1] = 0;
        }
        else
        {
                int a = 0,b = 0;
                char c;
                strcat(buf,t);

                if (0 == strcmp("=",t))
                {
                        printf("t==##%s##\n",t);
                        sscanf(buf,"%d%c%d",&a,&c,&b);
                        printf("------001-----%c--\n",c);

                        if ('+' == c)
                        {
                                sprintf(buf,"%d",a+b);
                        }
                        else if ('-' == c)
                        {
                                sprintf(buf,"%d",a-b);
                        }
                        else if ('*' == c)
                        {
                                sprintf(buf,"%d",a*b);
                        }
                        else if ('/' == c)
                        {
                                sprintf(buf,"%d",a/b);
                        }
                }
        }
        gtk_entry_set_text(GTK_ENTRY(data),buf);
        return;
}

int main(int argc,char *argv[])
{
        gtk_init(&argc,&argv);
        GtkWidget *w;
        w = gtk_window_new(GTK_WINDOW_TOPLEVEL);

        gtk_window_set_title(GTK_WINDOW(w),"计算器");

        GtkWidget *a = gtk_table_new(5,4,TRUE);
        gtk_container_add(GTK_CONTAINER(w),a);

        GtkWidget *entry = gtk_entry_new();
        gtk_entry_set_text(GTK_ENTRY(entry),"");
        gtk_editable_set_editable(GTK_EDITABLE(entry),FALSE);

        GtkWidget *b0 = gtk_button_new_with_label("0");
        GtkWidget *b1 = gtk_button_new_with_label("1");
        GtkWidget *b2 = gtk_button_new_with_label("2");
        GtkWidget *b3 = gtk_button_new_with_label("3");
        GtkWidget *b4 = gtk_button_new_with_label("4");
        GtkWidget *b5 = gtk_button_new_with_label("5");
        GtkWidget *b6 = gtk_button_new_with_label("6");
        GtkWidget *b7 = gtk_button_new_with_label("7");
        GtkWidget *b8 = gtk_button_new_with_label("8");
        GtkWidget *b9 = gtk_button_new_with_label("9");

        GtkWidget *b_add = gtk_button_new_with_label("+");
        GtkWidget *b_minus = gtk_button_new_with_label("-");
        GtkWidget *b_mul = gtk_button_new_with_label("*");
        GtkWidget *b_div = gtk_button_new_with_label("/");
        GtkWidget *b_equal = gtk_button_new_with_label("=");
        GtkWidget *b_del = gtk_button_new_with_label("c");

        gtk_table_attach_defaults(GTK_TABLE(a),entry,0,4,0,1);

        gtk_table_attach_defaults(GTK_TABLE(a),b0,0,1,4,5);
        gtk_table_attach_defaults(GTK_TABLE(a),b1,0,1,3,4);
        gtk_table_attach_defaults(GTK_TABLE(a),b2,1,2,3,4);
        gtk_table_attach_defaults(GTK_TABLE(a),b3,2,3,3,4);
        gtk_table_attach_defaults(GTK_TABLE(a),b4,0,1,2,3);
        gtk_table_attach_defaults(GTK_TABLE(a),b5,1,2,2,3);
        gtk_table_attach_defaults(GTK_TABLE(a),b6,2,3,2,3);
        gtk_table_attach_defaults(GTK_TABLE(a),b7,0,1,1,2);
        gtk_table_attach_defaults(GTK_TABLE(a),b8,1,2,1,2);
        gtk_table_attach_defaults(GTK_TABLE(a),b9,2,3,1,2);

        gtk_table_attach_defaults(GTK_TABLE(a),b_add,1,2,4,5);
        gtk_table_attach_defaults(GTK_TABLE(a),b_minus,2,3,4,5);
        gtk_table_attach_defaults(GTK_TABLE(a),b_mul,3,4,2,3);
        gtk_table_attach_defaults(GTK_TABLE(a),b_div,3,4,3,4);
        gtk_table_attach_defaults(GTK_TABLE(a),b_equal,3,4,4,5);
        gtk_table_attach_defaults(GTK_TABLE(a),b_del,3,4,1,2);

        g_signal_connect(b0,"pressed",G_CALLBACK( deal_num ),entry);
        g_signal_connect(b1,"pressed",G_CALLBACK( deal_num ),entry);
        g_signal_connect(b2,"pressed",G_CALLBACK( deal_num ),entry);
        g_signal_connect(b3,"pressed",G_CALLBACK( deal_num ),entry);
        g_signal_connect(b4,"pressed",G_CALLBACK( deal_num ),entry);
        g_signal_connect(b5,"pressed",G_CALLBACK( deal_num ),entry);
        g_signal_connect(b6,"pressed",G_CALLBACK( deal_num ),entry);
        g_signal_connect(b7,"pressed",G_CALLBACK( deal_num ),entry);
        g_signal_connect(b8,"pressed",G_CALLBACK( deal_num ),entry);
        g_signal_connect(b9,"pressed",G_CALLBACK( deal_num ),entry);

        g_signal_connect(b_add,"pressed",G_CALLBACK( deal_num ),entry);
        g_signal_connect(b_minus,"pressed",G_CALLBACK( deal_num ),entry);
        g_signal_connect(b_mul,"pressed",G_CALLBACK( deal_num ),entry);
        g_signal_connect(b_div,"pressed",G_CALLBACK( deal_num ),entry);
        g_signal_connect(b_equal,"pressed",G_CALLBACK( deal_num ),entry);
        g_signal_connect(b_del,"pressed",G_CALLBACK( deal_num ),entry);

        gtk_widget_show_all(w);

        gtk_main();

        return 0;

}
#endif

